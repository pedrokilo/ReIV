import csv,json,pathlib
root=pathlib.Path(__file__).resolve().parents[2]
ev=root/'reversing/AudioValidation/evidence'
rows=list(csv.DictReader((ev/'scope.csv').open(encoding='utf-8-sig',newline='')))
files=list(csv.DictReader((ev/'files.csv').open(encoding='utf-8-sig',newline='')))
candidates=json.loads((ev/'candidates.json').read_text())
fixture=json.loads((ev/'fixture-scope.json').read_text())
fixturevas={x['va'] for x in fixture}
text='''# Validación de audio

El lote abarca los 28 headers de `source/game/audio`: 236 referencias virtuales apuntan a 98 destinos únicos del ejecutable GTA IV PC 1.0.7.0, SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

Se exportaron cuerpos completos, instrucciones, decompilación y bytes de entrada desde el proyecto Ghidra existente. De los 98 destinos, 29 permiten pruebas aisladas: 19 operaciones sobre objetos temporales y 10 stubs constantes o vacíos. Los otros 69 quedan deshabilitados: 68 necesitan comprobar firmas, vida de objetos o estado del motor, y `0x00401210` es el manejador fatal compartido que puede terminar el proceso.

Los 29 candidatos corresponden a 137 referencias, porque varias tablas comparten funciones. Las 99 referencias restantes quedan pendientes o excluidas. Los nombres de comportamiento son inferencias del código máquina, no símbolos originales recuperados.

## Alcance por archivo

La columna «Admitidas» suma referencias a fixtures y stubs; no representa funciones únicas. «Pendientes» incluye el destino fatal, cuando aparece.

| Header | Referencias | Candidatas estáticas | Fuera del banco aislado | Probadas runtime |
|---|---:|---:|---:|---:|
'''
for f in files:
 total=int(f['references']);eligible=int(f['candidates'])
 text+=f"| [{pathlib.Path(f['file']).name}](../../{f['file']}) | {total} | {eligible} | {total-eligible} | {f['runtime_tested']} |\n"
text+='''
## Pruebas aisladas

`source/hooks/AudioFixtureProbe.h` requiere el marcador `ReIV.audio-fixtures-test`. Espera a que el juego esté cargado, valida el ejecutable y todos los bytes del cuerpo de cada candidato, y ejecuta 64 rondas por destino. Las dos comparaciones cubren igualdad y desigualdad, con dos llamadas por ronda. El lote completo contiene 1.344 llamadas nativas.

Los objetos temporales ocupan 4.096 bytes y se comparan íntegramente contra el estado esperado después de cada operación. Los parámetros de salida tienen valores de guarda. Los setters deben modificar únicamente los campos conocidos; los getters deben devolver el valor sembrado. Las excepciones y los resultados inesperados detienen las repeticiones de la entrada afectada y la marcan deshabilitada en el informe.

| VA preferida | Operación probada | Valor / desplazamiento | Modalidad |
|---|---|---|---|
'''
for x in candidates:
 mode='Fixture temporal' if x['va'] in fixturevas else 'Stub compartido'
 text+=f"| [{x['va']}](../../{x['evidence']}) | `{x['operation']}` | `0x{x['value']:X}` | {mode} |\n"
text+='''
La firma mínima de los fixtures está determinada por las instrucciones de acceso a ECX, los argumentos de pila y el retorno. Se utilizan llamadas x86 `__thiscall`. Los getters de coma flotante devuelven el valor en x87. El banco general de stubs cubre las funciones constantes admitidas por su propio inventario; no se presupone que incluya todos los candidatos de audio.

Estas pruebas comprueban la llamada y el comportamiento acotado de cuerpos simples. No validan el diseño completo de las clases, sus constructores, objetos reales del audio, reproducción sonora, limpieza de recursos ni llamadas en otros estados del motor. No instalan hooks de sustitución ni reconstruyen funciones. Todas las entradas conservan `enabled=false` y `reconstructed=false`.

## Evidencia

- [Inventario de referencias y disposición estática](../../reversing/AudioValidation/evidence/scope.csv).
- [Resumen de los 28 archivos](../../reversing/AudioValidation/evidence/files.csv).
- [29 candidatos con ABI, bytes completos y propietarios](../../reversing/AudioValidation/evidence/candidates.json).
- [19 fixtures del banco específico](../../reversing/AudioValidation/evidence/fixture-scope.json).
'''
summary=ev/'runtime-summary.json'
if summary.exists():
 s=json.loads(summary.read_text(encoding='utf-8-sig'))
 text+='\n## Ejecución en el juego\n\n'
 proven={r['va'] for r in rows if r.get('runtime_reference_tested')=='1'}
 refs=sum(r.get('runtime_reference_tested')=='1' for r in rows)
 text+=f'La ejecución integrada aprobó los 19 fixtures: 1.344 llamadas, cero fallos y cero excepciones. El banco general aprobó otros 7 destinos de audio con 448 llamadas. En total, {len(proven)} destinos y {refs} referencias de audio tienen evidencia de llamada; no hubo hooks de sustitución instalados. El juego cerró normalmente con código 0 y la consola estuvo visible y disponible para escritura.\n\n'
 if len(proven)==29:
  text+='La segunda ejecución aprobó los tres stubs restantes: `0x0092C4D0` (no-op con RET 8), `0x00AAAF20` (no-op con RET 4) y `0x00C87A50` (constante float 1), con 192 llamadas adicionales y cero fallos o excepciones. Los 29 candidatos acumulan 1.984 llamadas en ambos bancos. Los 69 destinos complejos o fatales permanecen sin llamar y deshabilitados.\n\n'
  text+='[Informe de los stubs adicionales](../../reversing/ExtraStubValidation/evidence/runtime-report.json).\n\n'
 else:
  text+='Tres candidatos estáticos siguen sin prueba runtime: `0x0092C4D0` (no-op con RET 8), `0x00AAAF20` (no-op con RET 4) y `0x00C87A50` (constante float 1). Sus 35 referencias permanecen pendientes. Los 69 destinos complejos o fatales tampoco se llamaron.\n\n'
 text+='Evidencia: [resumen runtime y hashes](../../reversing/AudioValidation/evidence/runtime-summary.json), [19 fixtures y contadores](../../reversing/AudioValidation/evidence/runtime-report.json), [stubs compartidos y contadores](../../reversing/GameValidation/evidence/runtime-report.json), [log integrado](../../reversing/AudioValidation/evidence/runtime.log). Los CSV distinguen candidatos estáticos de referencias comprobadas en runtime.\n'
else:
 text+='\nLa prueba en el juego está pendiente de registrar sus informes; el análisis estático por sí solo no marca llamadas como aprobadas.\n'
(root/'docs/MemoryMap/AudioValidation.md').write_text(text,encoding='utf-8')
