# Mapa de memoria de GTA IV 1.0.7.0

Inventario estático del EXE canónico, generado el **6 de octubre de 2026**. Este trabajo sólo ficha direcciones y su procedencia: no reconstruye funciones, instala hooks ni ejecuta el juego.

**[Abrir el visor local](index.html)**. Funciona sin servidor ni conexión, en un navegador moderno: busca `CPed`, `CEntity`, `rage::`, una VA o una RVA. La ficha de cada tipo muestra los descriptores, vtables, bases registradas y slots que se hayan encontrado. Puedes filtrar por sección y exportar los resultados a CSV.

| Inventario | Encontrado |
| --- | ---: |
| Nombres únicos de tipos RTTI presentes en el EXE | 4.016 |
| Tipos RTTI con al menos una vtable enlazada | 3.431 |
| Vtables enlazadas mediante RTTI | 3.478 |
| Slots virtuales fichados, con repeticiones entre tablas | 45.503 |
| Destinos virtuales distintos | 9.892 |
| Entradas de función detectadas por Ghidra | 28.035 |
| Destinos virtuales adicionales que no figuran como entradas en Ghidra | 6.106 |
| Direcciones de código distintas en el mapa combinado | 34.141 |
| Declaraciones de clases/structs en los headers raíz de IV-SDK | 181 |
| Declaraciones del SDK que coinciden por nombre con un tipo RTTI | 69 |
| Referencias de dirección del SDK para 1.0.7.0 | 438 |
| Menciones de direcciones del documento aportado | 219 |

**Todavía no conocemos el total exacto de clases ni de funciones del juego.** RTTI no cubre necesariamente todas las clases; incluye plantillas, tipos de librerías y componentes ajenos a la lógica del juego. Las clases sin RTTI pueden existir igualmente. Ghidra hizo un análisis global parcial, y sus entradas son candidatos que pueden contener thunks o límites mal determinados. Los destinos extra de vtable tienen una dirección a código, pero no una firma o un cuerpo analizado.

## Qué dirección tiene una clase

Una clase no ocupa una dirección única. Aquí se fichan:

- **TypeDescriptor:** metadatos RTTI del tipo.
- **Vtable:** tabla de punteros a funciones virtuales. Puede haber varias para un tipo.
- **Slots:** direcciones a las que apunta cada tabla, incluidas funciones heredadas o compartidas.
- **Referencias del SDK:** funciones, globales u otras direcciones declaradas por esa fuente.

Las instancias, como un ped o un vehículo concreto, se crean durante la ejecución y no tienen una dirección fija deducible de este mapa estático. La jerarquía RTTI puede incluir bases transitivas; no se presenta como una lista verificada de herencia directa.

### Ejemplos encontrados en el EXE

| Tipo | TypeDescriptor · VA estática | Vtable principal encontrada · VA estática |
| --- | --- | --- |
| `CPed` | `0x0108F53C` | `0x00D69844` |
| `CEntity` | `0x0108F4EC` | `0x00D83BAC` |
| `CVehicle` | `0x00F22240` | `0x00D82164` |
| `rage::fiDevice` | `0x0108F17C` | `0x00D53C84` |

La vtable de `CPed` coincide con `0x00D69844` en el documento aportado. Esa coincidencia concreta se corroboró con los enlaces RTTI del binario; las otras referencias del documento siguen sin validarse semánticamente.

## VA, RVA y offsets

El EXE tiene base preferida **`0x00400000`**. Las fichas guardan VA estática y RVA, siguiendo la [definición del formato PE de Microsoft](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#general-concepts):

```text
RVA              = VA estática − 0x00400000
VA en ejecución  = base real del módulo + RVA
```

Por ejemplo, la vtable de `CPed` tiene RVA `0x00969844`. Si el módulo se carga en otra base, sumar esa RVA a la base real. El visor calcula el resultado para la base que escribas; **no lee ni observa la base de un proceso abierto**. Un offset de campo dentro de un objeto no es una VA ni una RVA.

## Archivos del inventario

### Fichas por clase

Los 4.016 headers también incluyen sus destinos conocidos como metadatos pendientes: 45.503 registros de slots virtuales y 55 referencias de funciones SDK asociadas por propietario RTTI exacto. Los [detalles de cobertura y estados](PendingHooks.md) explican el [índice de direcciones pendientes](pending_hooks.csv) y las [referencias SDK sin propietario asociado](pending_hooks_unmatched.csv). Estos registros no activan llamadas ni instalan hooks; nombres y ABI siguen pendientes salvo la evidencia específica del catálogo verificado.

La [correlación de clases y hooks](ClassesAndHooks.md) cruza los 4.016 tipos RTTI con `docs/hooks.csv`: direcciones de metadatos, métodos catalogados, estado de reconstrucción, pruebas y enlaces a headers y evidencia. Se regenera con el catálogo de hooks.

El visor enlaza estas fichas al seleccionar su clase en **Tipos RTTI**, mediante «Abrir ficha documentada» y «Abrir datos JSON».

- [CEntity](classes/CEntity.md): RTTI, 51 slots candidatos contrastados con el EXE y tres nombres referenciados al SDK. Incluye [datos estructurados](classes/CEntity.json). Los nombres, firmas y offsets del SDK conservan su estado pendiente de validación.
- [CPhysical](classes/CPhysical.md): RTTI, 72 slots candidatos y comparación por índice con CEntity: 25 destinos iguales, 26 diferentes y 21 fuera de su inventario. Incluye [datos estructurados](classes/CPhysical.json), referencias de funciones y offsets del SDK pendientes de validar.
- [CPed](classes/CPed.md): RTTI, 81 slots candidatos y comparación con CPhysical: 33 destinos iguales, 39 diferentes y nueve fuera de su inventario. Incluye [datos estructurados](classes/CPed.json), referencias de métodos y offsets del SDK pendientes de validar.
- [CVehicle](classes/CVehicle.md): RTTI, 111 slots candidatos y comparación con CPhysical: 60 destinos iguales, 12 diferentes y 39 fuera de su inventario. Incluye [datos estructurados](classes/CVehicle.json), el slot de Fix y 11 referencias de funciones del SDK pendientes de validar.
- [CDynamicEntity](classes/CDynamicEntity.md): eslabón entre CEntity y CPhysical, con 55 slots candidatos: 33 destinos iguales a CEntity, 18 diferentes y cuatro fuera de su inventario. Incluye [datos estructurados](classes/CDynamicEntity.json) y las referencias GetBoneMatrix/GetBoneMatrix2 del SDK.

### Cruce automático de nombres del SDK

La pestaña **Cruces de nombres SDK** permite buscar clase, destino y nombre propuesto. Se detectaron 16 wrappers virtuales de sintaxis explícita en los headers raíz del SDK; el parser es conservador y no cubre todas las maneras de expresar una llamada virtual. Los cruces generan 1.723 referencias para 1.713 slots, sin modificar las etiquetas originales de Ghidra.

Se distinguen tres criterios:

- `sdk_exact_function_address`: el destino coincide con una referencia de función de dirección fija del SDK.
- `sdk_exact_owner_slot`: el nombre de clase RTTI y el índice coinciden con los de un wrapper virtual del SDK.
- `sdk_shared_virtual_target`: un slot apunta al mismo destino que un wrapper enlazado en otra tabla. Se conservan clase, slot y tabla de origen; **no demuestra que el método tenga el mismo significado ni firma**. Puede tratarse de un thunk o un cuerpo compartido.

No se propagan nombres por herencia ni se elige uno cuando hay varios candidatos. Todos estos cruces tienen estado `sdk_name_not_validated`; no constituyen funciones identificadas semánticamente, reconstruidas ni validadas. El generador actualiza los cruces y enlaces del visor al regenerar el mapa.

plugin_IV e IV-SDK.Net aportan nombres por dirección con el mismo criterio: `contrib/plugin-iv-patterns.py` busca cada patrón en las secciones ejecutables y solo conserva coincidencias únicas; `contrib/sdknet-addresses.py` lee `1070.ini`; `contrib/crossref-sdks.py` compara offsets de campos. Todo queda como pista no validada y la columna `reference_names` de [hooks.csv](../hooks.csv) recoge las coincidencias exactas por dirección.

| Archivo | Contenido |
| --- | --- |
| [classes.csv](classes.csv) | Nombre decorado y legible, dirección del descriptor, vtables y bases RTTI |
| [vtables.csv](vtables.csv) | Dirección de tabla y locator, desplazamiento del subobjeto y slots estimados |
| [virtual_slots.csv](virtual_slots.csv) | Clase, tabla, índice del slot y destino a código |
| [sdk_virtual_methods.csv](sdk_virtual_methods.csv) | Wrappers virtuales explícitos del SDK, clase, índice y fuente |
| [sdk_slot_crossrefs.csv](sdk_slot_crossrefs.csv) | Nombres candidatos por slot, criterio de coincidencia y procedencia |
| [function_entries.csv](function_entries.csv) | Entradas de Ghidra en secciones ejecutables, sin equipararlas a funciones validadas |
| [code_addresses.csv](code_addresses.csv) | Entradas de Ghidra y destinos virtuales adicionales, sin duplicar direcciones |
| [sdk_classes.csv](sdk_classes.csv) | Declaraciones del SDK y sus coincidencias RTTI por nombre |
| [sdk_addresses.csv](sdk_addresses.csv) | Direcciones del SDK, archivo y línea de origen |
| [plugin_iv_patterns.csv](plugin_iv_patterns.csv) | Patrones `gpattern` de plugin_IV resueltos en el EXE, con número de coincidencias ([resumen](PluginIvPatterns.md)) |
| [sdknet_addresses.csv](sdknet_addresses.csv) | Offsets nombrados de IV-SDK.Net para 1.0.7.0 (`1070.ini`) resueltos en el EXE |
| [FunctionClassification.md](FunctionClassification.md) | Clasificación de funciones binarias por procedencia y estado de reversión ([CSV](function_classification.csv), `tools/ReIV.Tools`) |
| [DependencyProvenance.md](DependencyProvenance.md) | Procedencia de las dependencias externas de los cuerpos de CPlayerPed ([CSV](dependency_provenance.csv)) |
| [SdkCrossReference.md](SdkCrossReference.md) | Cruce de offsets de campos entre IV-SDK, plugin_IV e IV-SDK.Net y el layout observado de CPlayerPed || [historical_references.csv](historical_references.csv) | Direcciones del documento, línea, contexto y versión cuando aparece en esa misma línea |
| [sections.json](sections.json) | Rangos y permisos de las secciones del PE |
| [summary.json](summary.json) | Recuentos y hash del binario |

El [catálogo de reconstrucción](../functions.csv) permanece separado. Añadir una dirección al mapa no marca una función como reconstruida, hookeada, validada o independiente del EXE.

## Procedencia y comprobaciones

- **EXE:** SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`. Se exige ese hash antes de extraer.
- **RTTI:** nombres de tipos con cabecera compatible; locators, jerarquías y arrays de bases enlazados mediante punteros válidos. Los destinos de slots deben apuntar a bytes presentes en una sección ejecutable. La lectura termina en el primer puntero que no cumple esa condición y tiene un límite de 512 slots; no demuestra por sí sola el límite semántico exacto de una tabla. El formato de estructuras se contrastó con `rttidata.h` de las herramientas MSVC instaladas.
- **Ghidra:** exportación de sólo lectura del proyecto `build/ghidra-project/ReIV1070.gpr`. No se reanaliza ni modifica el proyecto al exportar. Se conserva el indicador de análisis global parcial.
- **SDK:** sólo los headers raíz de `contrib/IV SDK/IV-SDK-main/include`. Se extrae el primer argumento literal de `AddressSetter::Get/GetRef`, correspondiente a 1.0.7.0. Son referencias de la fuente, no ABI, nombres o comportamientos comprobados en runtime. La asociación con clases RTTI usa coincidencia exacta de nombre.
- **Documento:** `gta4_memory_addresses_completo_es.md`, SHA-256 `dada16f8e53a3aeb4432618f9aa2b0db70590fa1982afa30ef1fb6e858665e8b`. Mezcla versiones de GTA IV y EFLC y contiene referencias explícitamente sin verificar. Se registran sus menciones con contexto, sin importar sus direcciones como confirmadas para el EXE canónico. Estar dentro de una sección sólo significa que la ubicación está mapeada.

Los nombres anónimos, `FUN_*` y `virtual_entry_*` se conservan como tales. No se adivinan propietarios, nombres de método, direcciones de instancias ni firmas ausentes.

## Regenerar

Resultados de los bancos de llamadas y auditoría runtime: [game](GameValidation.md), [audio](AudioValidation.md), [animación](AnimationValidation.md), [NMutils](NMutilsValidation.md), [rage](RageValidation.md) y [ART](ARTValidation.md). Una coincidencia de dirección, una llamada de cuerpo simple y una reconstrucción son estados distintos.

La [pasada adicional de pendientes](PendingAnalysis.md) contiene la cobertura actual, los nuevos bancos, el reanálisis de Ghidra y los callbacks recuperados para tipos antes desconocidos. Sus totales posteriores complementan los reportes históricos anteriores.

La [pasada de funciones complejas](ComplexValidation.md) añade fixtures con ramas, objetos anidados y modos de destructor sin liberación; distingue esas pruebas restringidas de la validación completa de funciones.

Con el proyecto y Ghidra locales disponibles:

```powershell
powershell -ExecutionPolicy Bypass -File .\reversing\MemoryMap\export-ghidra.ps1
& 'C:\Users\pedro\AppData\Local\Programs\Python\Python314\python.exe' .\contrib\build-memory-map.py
```

El generador acepta `--exe`, `--reference` y `--ghidra-export` para indicar otras rutas. Los proyectos de Ghidra y el EXE permanecen locales. Los CSV, resumen y visor se incluyen en el repositorio para consultar el mapa sin esas herramientas.
