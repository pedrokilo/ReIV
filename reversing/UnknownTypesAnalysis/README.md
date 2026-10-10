# Análisis de los 585 tipos sin métodos conocidos

EXE canónico SHA-256: `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`. Escáner reproducible: `python reversing/UnknownTypesAnalysis/analyze.py`.

| Resultado | Tipos |
| --- | --- |
| base_type_only_no_own_locator_or_vtable | 578 |
| type_descriptor_only_no_own_locator_or_vtable | 7 |

Se revisaron referencias alineadas a los descriptores RTTI, localizadores completos x86, jerarquías y punteros a tablas propias. Los descriptores de tipos base presentes en jerarquías de clases derivadas no establecen direcciones de métodos propios de esas bases. No se atribuyen métodos de las clases derivadas a sus bases.

El resultado distingue presencia de RTTI y relación de herencia de existencia de un objeto completo con tabla virtual propia. La ausencia de tabla propia en este inventario no prueba que una clase carezca de métodos no virtuales: para identificarlos hacen falta referencias de código y análisis de implementaciones. Ninguna llamada se ejecuta ni se habilita con este análisis.

Todos los 585 tipos están enumerados en [unknown-types.csv](evidence/unknown-types.csv); las relaciones documentadas en [base-relations.json](evidence/base-relations.json). Las referencias de métodos propios recuperadas, si existen, quedan en [recovered-own-methods.csv](evidence/recovered-own-methods.csv), pendientes de validación.

## Referencias adicionales mediante excepciones MSVC

`python reversing/UnknownTypesAnalysis/analyze_eh.py` valida cadenas ThrowInfo → CatchableTypeArray → CatchableType y exporta [recovered-eh-methods.csv](evidence/recovered-eh-methods.csv). Son seis callbacks propios de cuatro tipos, cuatro de copia y dos de destrucción durante unwind. Los nombres describen su función en los metadatos; el ABI y su ejecución permanecen pendientes. No son métodos heredados ni entradas virtuales. La evidencia completa está en [eh-summary.json](evidence/eh-summary.json).

| Propietario | Tipo de callback | VA |
| --- | --- | --- |
| __non_rtti_object | msvc_eh_copy_constructor_callback | `0x00d1d905` |
| bad_typeid | msvc_eh_copy_constructor_callback | `0x00d1d8cb` |
| exception | msvc_eh_copy_constructor_callback | `0x00d1d7fa` |
| bad_cast | msvc_eh_copy_constructor_callback | `0x00d1d885` |
| __non_rtti_object | msvc_eh_unwind_destructor_callback | `0x00d1d922` |
| bad_cast | msvc_eh_unwind_destructor_callback | `0x00d1d8a2` |

## Decompilación adicional

REA/Ghidra devolvió pseudocódigo para cinco de los seis callbacks EH. Para VA `0x00D1D922` rechazó la consulta; se conserva esa limitación y la dirección solo está acreditada por la cadena de metadatos, sin llamada ejecutada. [Resultado completo](evidence/eh-callbacks-rea-decompilation.json).
