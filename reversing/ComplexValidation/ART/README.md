# ART: funciones con flujo condicional y dependencias

Se revisan 164 destinos y 206 referencias que quedaron pendientes después de los primeros bancos. Se preparan quince destinos adicionales (960 llamadas previstas), sin habilitar hooks ni reconstruir clases. [Inventario completo](evidence/complex-inventory.csv).

| Resultado estático | Destinos |
| --- | --- |
| direct/indirect callee ABI and state dependencies unresolved | 117 |
| full CFG and nested pointer bounds not established | 14 |
| this adjustment to destructor; live allocation/TLS/destruction flags required | 4 |
| complete CFG isolated fixture prepared | 15 |
| global/TLS state or object lifetime/unsupported operations unresolved | 14 |

## Cuerpos completos preparados

Los ocho setters de float escriben únicamente cuando el bit 2 de `this+232` está limpio. El fixture alterna ambos resultados del bit y comprueba todo el almacenamiento. Las copias x87 usan floats finitos controlados; los getters con punteros usan buffers anidados propios. La salida de nueve floats conserva los huecos de cada vector y los márgenes del buffer.

| VA | Operación observada |
| --- | --- |
| `0x005e35c0` | guarded_float_store · offset 380 |
| `0x005e35f0` | guarded_float_store · offset 388 |
| `0x005e3620` | guarded_float_store · offset 392 |
| `0x005e3650` | guarded_float_store · offset 396 |
| `0x005ee8c0` | guarded_float_store · offset 296 |
| `0x005ee8f0` | guarded_float_store · offset 300 |
| `0x005ee920` | guarded_float_store · offset 304 |
| `0x005ee950` | guarded_float_store · offset 308 |
| `0x005e41c0` | guarded_copy3 · offset 0 |
| `0x005e4460` | guarded_zero3 · offset 0 |
| `0x005eee40` | reset_and_guarded_copy · offset 0 |
| `0x005ef060` | guarded_zero1 · offset 0 |
| `0x005fdcf0` | select_this · offset 0 |
| `0x005fdd60` | nested_read · offset 0 |
| `0x00686cd0` | zero_output9 · offset 0 |

Pseudocódigo observado en `0x005E35C0`: `if (!(this[232] & 4)) store_float(this+380, arg1); return;`. En `0x005FDD60`: `return load_u32(load_ptr(this+80)+844);`. En `0x005FDCF0`: `return (this[10]&8) ? nullptr : this;`. Estas expresiones describen cuerpos de máquina completos; no declaran sus nombres originales ni el layout completo de las clases. Las direcciones de saltos locales se validan contra límites de instrucciones.

## Dependencias que todavía impiden probar funciones completas

- `ART::AgentComponentsManager`, `0x005D7090`: Ghidra delimita un cuerpo de 85 bytes con dos llamadas indirectas. Requiere almacenamiento real de componentes, objetos apuntados y ABI de las entradas virtuales; un objeto de bytes aislado no satisface esas dependencias.
- `ART::Rockstar::NmRsEngine`, `0x005E1510/20/30/40`: thunks ajustan ECX por 24/32/8/16 y saltan al destructor `0x005E0C90`. Ese cuerpo libera recursos e invoca otras funciones. No es seguro sustituir su objeto por un buffer y observar únicamente la primera rama.
- `ART::Rockstar::CBUTaskBase` y derivados, `0x005EFC30`: guarda argumentos en `this+12/+16` y llama una entrada virtual `vtable+28`. Requiere una instancia funcional y el contrato de ese callback.
- Las funciones de actualización de efectores combinan estado del personaje, physics y dispatch virtual. Deben resolverse sus punteros y llamadas antes de ejecutar el cuerpo completo.

Los slices del inventario previo terminan al primer RET observado; no se consideran prueba de CFG completo. Solo los quince cuerpos del fixture se han examinado hasta un retorno final, con todos sus saltos locales incluidos. El análisis estático restante no acredita llamadas.

Reproducción: `python reversing/ComplexValidation/ART/prepare.py`, `python reversing/ComplexValidation/ART/analyze_remaining.py`; el runner `run.ps1` usa el EXE canónico y restaura archivos/marcadores anteriores.
