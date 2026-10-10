# Organización del código de ReIV

La plantilla parte de IV-SDK: sus headers describen clases del juego y RAGE, `Scripting` agrupa los natives y `injector` implementa la infraestructura de hooks. ReIV distribuye las implementaciones propias por su función:

```text
source/
├── core/
│   └── ReIV.cpp                  Entrada del ASI y eventos de inicio
├── rage/
│   ├── AtStringHash.h            Primera función reconstruida del motor
│   ├── base/src/                 Módulos base: atl, rline, grcore, physics, etc.
│   ├── suite/src/                snet, fragment, crmotiontree, rmptfx, etc.
│   ├── framework/src/            Módulos de framework presentes en el inventario
│   └── script/src/               Tipos de scripting del motor
├── game/                        Tipos GTA IV agrupados por sistema
│   ├── task/                    Tareas: Movement, Combat, Vehicle, etc.
│   ├── network/                 Objects, Arrays, Events, General, etc.
│   ├── camera/                  Cámaras y viewports
│   ├── Peds/                    Peds, inteligencia y movimiento
│   ├── Vehicles/                Vehículos
│   ├── scene/                   Entidades, portales y mundo
│   └── ...                      Audio, animación, renderer, eventos, etc.
├── Scripting/                   Futuras reconstrucciones de scripting
└── hooks/
    ├── AtStringHashProbe.h       Banco, trampoline y conexión del hook
    └── AtStringHashSignature.h   Identificación del original canónico
```

`Scripting` se conserva en Git mediante `.gitkeep`. Las clases y natives de referencia del SDK permanecen en `contrib/IV SDK/IV-SDK-main/include`; la infraestructura de terceros sigue en su carpeta `injector`. Se añaden a `source` implementaciones propias conforme se identifiquen y reconstruyan.

## Archivos por tipo RTTI

Los 4.016 tipos de [classes.csv](../docs/MemoryMap/classes.csv) tienen un header individual: 1.223 en `game`, 2.745 en `rage` y 48 en `external/ART` o `external/NMutils`. Los tipos anidados se agrupan en carpetas de sus propietarios. Los nombres con parámetros de plantilla se convierten en nombres de archivo válidos para Windows con un hash estable para distinguirlos.

El [índice de archivos](class-files.csv) relaciona el nombre RTTI exacto con su ruta. Cada header conserva nombre decorado, clase/struct, descriptor VA/RVA, sección, estado, bases RTTI, locators, vtables y coincidencia con el SDK. Las bases pueden ser transitivas; los datos no demuestran herencia directa ni layouts.

`game` sigue la organización por sistemas y los nombres de carpetas de `E:/Original/gta5/src/dev_ng/game`, incluidas sus subcarpetas. La asignación se basa en familias de nombres de GTA IV y, cuando existe una coincidencia única compatible, en el nombre del header de referencia. No se copia código de GTA V. Los tipos anidados permanecen junto a su propietario. El [mapa de carpetas](../reversing/MemoryMap/game-folders.csv) conserva la asignación y su criterio; el generador lo lee para mantener las rutas sin necesitar el árbol de referencia.

Los 2.745 headers RTTI de `rage` siguen los módulos de `E:/Original/gta5/src/dev_ng/rage`, conservando las capas `base/src`, `suite/src`, `framework/src` y `script/src`. Se usa el directorio de un header de referencia cuando su nombre coincide de forma única; los demás se asignan por familia del tipo. El [mapa de carpetas RAGE](../reversing/MemoryMap/rage-folders.csv) documenta esa clasificación y permite regenerar las mismas rutas. La organización no equivale a confirmar el módulo original de GTA IV. `rage/AtStringHash.h`, que ya contiene una función reconstruida, conserva su ruta y sus includes actuales.

Los tipos simples tienen una declaración adelantada dentro de `reiv::game`, `reiv::rage`, `reiv::ART` o `reiv::NMutils`. Las declaraciones de tipos anidados y plantillas quedan pendientes: el CSV no define sus propietarios ni parámetros. Los datos están en un espacio de nombres único bajo `reiv::memory_map`; no se añaden campos, métodos, cuerpos ni hooks ejecutables sin evidencia. Los headers requieren C++17. Sus metadatos no ejecutan llamadas ni instalan hooks, incluso al incluirlos.

Cada uno de los 4.016 headers contiene un bloque generado con `pending_hook_count` y `pending_hooks`, usando `core/PendingHook.h`. Hay 45.564 registros asociados: 45.503 slots virtuales, 55 referencias de funciones SDK y seis callbacks de excepciones MSVC, repartidos entre 3.435 tipos. Los otros 581 conservan el bloque con recuento cero. Se guardan VA/RVA, tabla, slot, nombres candidatos y procedencia, siempre con `enabled=false` y `reconstructed=false`. No se generan wrappers de firma desconocida. El [índice pending_hooks.csv](../docs/MemoryMap/pending_hooks.csv) enlaza los registros con sus archivos; [PendingHooks.md](../docs/MemoryMap/PendingHooks.md) detalla los cruces exactos, las referencias sin propietario y los límites de validación.

Para generar o comprobar los archivos de nuevo, ejecutar `python reversing/MemoryMap/generate-class-headers.py` desde la raíz. El generador conserva archivos idénticos y se detiene antes de escribir si encuentra un header editado o preexistente con contenido distinto.

## Métodos vinculados al original

El [catálogo de direcciones y hooks](../docs/ReversedClasses.md) distingue pruebas de wrappers, reconstrucciones y hooks instalados. La [guía del proceso](../docs/AddressBindingProcess.md) explica cómo añadir el siguiente método. `reiv::debug::Initialize`, en `core/DebugLog`, abre siempre la consola de depuración al inicializar ReIV, sin marcador ni variable de entorno. Muestra colores, hora y archivo/línea, escribe `ReIV.log` y exporta `ReIV-runtime-hooks.csv`.

El banco de llamadas originales conserva el marcador independiente `ReIV.original-calls-test`; abrir la consola no inicia ese banco. El marcador `ReIV.validation-test` controla el cierre de validación. Los destinos pendientes con firma o ABI desconocidas siguen deshabilitados: registrar o mostrar su dirección no ejecuta la función ni verifica su comportamiento.

La capa `core/OriginalCall.h/.cpp` resuelve RVA para el EXE canónico con comprobación de hash y bytes. El primer wrapper está en `game/scene/CDynamicEntity.cpp`: `GetBoneMatrix` llama al original mediante `__thiscall`, recibiendo una entidad real del SDK. Su declaración propia se conserva en `reversing/MemoryMap/declarations/CDynamicEntity.inc`, que el generador inserta en el header correspondiente. [Uso y evidencia](../reversing/OriginalCalls/README.md). Pasó 64 llamadas en juego al hueso raíz del jugador durante la carga de escena; no es una implementación reconstruida ni valida otros huesos o estados de juego.
