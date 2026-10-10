# Direcciones pendientes por tipo RTTI

Los 4.016 headers de [classes.csv](classes.csv) incluyen un bloque generado de direcciones candidatas para reconstrucción. El [índice pending_hooks.csv](pending_hooks.csv) permite buscar cada destino, su propietario RTTI exacto y el archivo donde se registra.

| Cobertura | Cantidad |
| --- | ---: |
| Headers con bloque de direcciones pendientes | 4.016 |
| Tipos con al menos un destino asociado | 3.435 |
| Tipos sin destino de función asociado por nombre exacto | 581 |
| Registros de slots virtuales | 45.503 |
| Referencias de funciones SDK asociadas | 55 |
| Callbacks de metadatos de excepciones MSVC | 6 |
| Registros totales asociados a headers | 45.564 |
| Referencias SDK sin propietario RTTI exacto | 165 |

Son registros de inventario, no 45.564 funciones distintas. Una dirección puede repetirse en varias tablas, slots y tipos; también puede aparecer como referencia SDK. Los límites de las tablas siguen siendo los estimados por el mapa estático. Los seis callbacks adicionales pertenecen a cuatro tipos y proceden de [cadenas de metadatos de excepciones](../../reversing/UnknownTypesAnalysis/README.md); permanecen sin prueba de llamada. [Cobertura y pruebas actuales](PendingAnalysis.md).

## Fuentes y asociación

- [virtual_slots.csv](virtual_slots.csv): cada registro conserva propietario, VA/RVA del destino, VA de la vtable, índice del slot, etiqueta y nombres candidatos del SDK. El propietario debe existir en `classes.csv`.
- [sdk_addresses.csv](sdk_addresses.csv): se incorporan sólo filas `function_reference` con `mapped=True` y `executable=True`. Se asignan a un header únicamente cuando `owner` coincide exactamente con un nombre RTTI. Las demás se conservan en [pending_hooks_unmatched.csv](pending_hooks_unmatched.csv), sin archivo asignado.

Una coincidencia de dirección o slot propone nombres; no confirma el significado, la firma, la convención de llamada ni el layout del objeto. Los nombres compartidos entre tablas conservan esta limitación.

## Qué contiene cada header

El bloque `BEGIN GENERATED PENDING HOOK ADDRESSES` usa [PendingHook.h](../../source/core/PendingHook.h) y el espacio de nombres de metadatos propio del tipo. Expone `pending_hook_count` y `pending_hooks`, con almacenamiento `constexpr` cuando hay destinos. Para los 581 tipos sin destinos asociados, el recuento es cero y el puntero es `nullptr`.

Cada registro conserva VA, RVA, vtable, slot, etiqueta, nombres candidatos, evidencia y origen (`VirtualSlot` o `SdkFunctionReference`). Para referencias SDK sin slot, la vtable es cero y el índice es `-1`. Se comprueba que `VA - RVA = 0x00400000`; en ejecución el destino se obtiene como base real del módulo más RVA.

Todos los registros se generan con `enabled=false` y `reconstructed=false`. No contienen una firma invocable, no llaman al destino y no instalan parches ni hooks automáticamente. `runtimeReferenceTested` sólo indica que la misma referencia de clase, método y RVA figura como probada en [hooks.csv](../hooks.csv); no valida todos los slots que compartan esa dirección.

Actualmente esa marca corresponde a la referencia SDK de `CDynamicEntity::GetBoneMatrix`. Su wrapper y su prueba permanecen separados de estos metadatos. El catálogo [ReversedClasses.md](../ReversedClasses.md) y [ClassesAndHooks.md](ClassesAndHooks.md) siguen mostrando las entradas verificadas de `hooks.csv`, sin convertir los candidatos masivos en funciones verificadas.

## Continuar la reconstrucción

Para convertir un candidato en wrapper, identificar el método y comprobar firma, ABI, argumentos y retorno contra el ejecutable canónico. Después añadir la declaración y el `.cpp`, usar la capa `OriginalCall` y registrar las comprobaciones en `hooks.csv`. La [guía del proceso](../AddressBindingProcess.md) describe las pruebas y la evidencia. Instalar una sustitución requiere además una implementación reconstruida y tratamiento correcto de la llamada al original.

## Regenerar

Desde la raíz del repositorio:

```powershell
python reversing/MemoryMap/generate-class-headers.py
```

El generador usa `pending_hooks.py` para recrear los bloques y ambos índices. Conserva las declaraciones propias mediante el mecanismo existente del generador; rechaza cambios ajenos al bloque generado que no coincidan con el contenido previsto. Los cambios manuales dentro del bloque de direcciones se reemplazan al regenerar.
