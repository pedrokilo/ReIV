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

- [CEntity](classes/CEntity.md): RTTI, 51 slots candidatos contrastados con el EXE y tres nombres referenciados al SDK. Incluye [datos estructurados](classes/CEntity.json). Los nombres, firmas y offsets del SDK conservan su estado pendiente de validación.
- [CPhysical](classes/CPhysical.md): RTTI, 72 slots candidatos y comparación por índice con CEntity: 25 destinos iguales, 26 diferentes y 21 fuera de su inventario. Incluye [datos estructurados](classes/CPhysical.json), referencias de funciones y offsets del SDK pendientes de validar.
- [CPed](classes/CPed.md): RTTI, 81 slots candidatos y comparación con CPhysical: 33 destinos iguales, 39 diferentes y nueve fuera de su inventario. Incluye [datos estructurados](classes/CPed.json), referencias de métodos y offsets del SDK pendientes de validar.

| Archivo | Contenido |
| --- | --- |
| [classes.csv](classes.csv) | Nombre decorado y legible, dirección del descriptor, vtables y bases RTTI |
| [vtables.csv](vtables.csv) | Dirección de tabla y locator, desplazamiento del subobjeto y slots estimados |
| [virtual_slots.csv](virtual_slots.csv) | Clase, tabla, índice del slot y destino a código |
| [function_entries.csv](function_entries.csv) | Entradas de Ghidra en secciones ejecutables, sin equipararlas a funciones validadas |
| [code_addresses.csv](code_addresses.csv) | Entradas de Ghidra y destinos virtuales adicionales, sin duplicar direcciones |
| [sdk_classes.csv](sdk_classes.csv) | Declaraciones del SDK y sus coincidencias RTTI por nombre |
| [sdk_addresses.csv](sdk_addresses.csv) | Direcciones del SDK, archivo y línea de origen |
| [historical_references.csv](historical_references.csv) | Direcciones del documento, línea, contexto y versión cuando aparece en esa misma línea |
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

Con el proyecto y Ghidra locales disponibles:

```powershell
powershell -ExecutionPolicy Bypass -File .\reversing\MemoryMap\export-ghidra.ps1
& 'C:\Users\pedro\AppData\Local\Programs\Python\Python314\python.exe' .\contrib\build-memory-map.py
```

El generador acepta `--exe`, `--reference` y `--ghidra-export` para indicar otras rutas. Los proyectos de Ghidra y el EXE permanecen locales. Los CSV, resumen y visor se incluyen en el repositorio para consultar el mapa sin esas herramientas.
