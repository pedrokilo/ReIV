# Constructor candidato 0x009C1910

Este documento conserva el comportamiento observado y los contratos del cuerpo reconstruido con dependencias explícitas. La comparación aislada descrita al final valida ese cuerpo bajo los contratos del banco; la construcción nativa en el juego sigue pendiente. El receptor llega en ECX; los tres argumentos están en ESP inicial +4, +8 y +12. La salida pone el receptor en EAX y termina con RET 12. El cuerpo conocido ocupa [009C1910,009C1C84).

## Pseudocódigo ordenado

`call(va, receiver, arguments)` representa una llamada original cuyo contrato puede seguir pendiente. `G[va]` representa memoria global canónica reubicada. `W/R` escriben/leen el tamaño indicado; no implican nombres semánticos. Los valores flotantes transportados con MOVSS se conservan como bits; las operaciones x87 se indican explícitamente.

```text
this = ECX; a1 = stack[4]; a2 = stack[8]; a3 = stack[12]
call(008ABF10, this, [a1,a2])
W32(this+0, rebased(00D819C4))
call(00C68B50, this+E80, [])
call(004475C0, this+EAC, [])
W32(this+EBC, G32[012308B0])
W32(this+EC0, G32[00F21F10]); W32(this+EC4, G32[00F21F14])
W32(this+EC8, G32[00F21F18]); W32(this+ED0, G32[00F21F20])
W32(this+ED4, G32[00F21F24]); W32(this+ED8, G32[00F21F28])
call(00B2A8F0, this+80, [1])
call(00B29E50, unknown_receiver, [this+80])
G32[01724200] = 0
p = call(00817F20, unknown_receiver, [a3])
W32(this+228, p)
if G32[010D0170] != 1 && G32[010E1984] == G32[00E3447C]
   && G32[00F0E4A0] != 12hex:
    call(00920CD0, p ? p+60 : 0, [this])
    p = R32(this+228)
    call(00921050, p ? p+60 : 0, [])
G32[01724210] = 100
p = R32(this+228)
W32((p ? p+60 : 0)+3D4, FFFFFFFF)
W32(R32(this+21C)+12C, 0)
if R8(this+218)==0 || R8(this+219)==0:
    call(009BE4C0, this, [])
edi = G32[011DDE74]
random = call(00D0D21A, unknown_receiver, []) & FFFF
f = x87_FILD_int32(random)
saved_control_word = x87_FNSTCW()
f = x87_FMUL_float32(f, G32[00EBE1D8])
f = x87_FMUL_float32(f, G32[00D819BC])
x87_FLDCW(saved_control_word | 0C00)
qword = x87_FISTP_int64(f)  // preserves x87 precision/exceptions; truncation mode
edi = wrap_u32(edi - low32(qword) + 60000)
x87_FLDCW(saved_control_word)
G32[016180EC] = edi
W32(this+260, R32(this+260) | 80)
G32[016180FC] = call(008631E0, unknown_receiver, [rebased(00D8195C)])
W32(this+A94, G32[00D8D70C])
call(00447610, this+EAC, [x87_FLDFSTP_float32(G32[00D8D70C])])
call(0089E5A0, this, [x87_FLDFSTP_float32(R32(this+A94))])
call(009720E0, R32(this+21C)+110, [])
G32[01724214] = rebased(016180E8)
p = R32(this+228)
W32(this+E74,0); W32(this+E78,0); W8(this+E70,0)
W8((p ? p+60 : 0)+416,0)
p224 = R32(this+224)
W8(this+E71,0)
W32(p224+EC,G32[00D50978]); W32(p224+E8,2)
if G32[010D0170]==1 || G32[010E1984]!=G32[00E3447C]
   || G32[00F0E4A0]==12hex:
    r = call(00797D70, unknown_receiver, [])
    value = G32[010CF7E0]
    if G32[010D00A0] == r: value = wrap_u32(value+1)
    W32(this+68,value)
call_import(IAT_00D4D4B8, [G32[01724234],G32[01724240],0,rebased(01724200)])
W32(this+E7C,this)
allocation = call(004011D0, unknown_receiver, [60hex])
if allocation != 0: allocation = call(008DA9A0, allocation, [])
W32(this+EA8,allocation)
W8(this+63,FF)
W8(this+EA6,0); W8(this+EA4,0); W8(this+EA5,0); W8(this+EA7,0)
W32(this+EB0,0); W32(this+EB4,0); W32(this+EB8,0)
W32(this+EE0,0); W32(this+EE4,0)
W32(this+EE8,G32[00D81958]); W32(this+EEC,G32[00D81958])
W32(this+EF0,FFFFFFFF); W32(this+EF4,0)
if low8(call(00878A00,R32(this+228),[])) != 0: G8[00F3FDDC] = 1
return this
```

La llamada 00817F20 recibe a3: ESP es el original menos 28 bytes (24 del prólogo y el argumento cdecl todavía apilado para 00B29E50), de modo que ESP+0x28 coincide con ESP original+12. El primer helper 008ABF10 recibe a1 y a2. Este cálculo se conserva en el ledger.

## Precondiciones y límites

Se necesita al menos EF8 bytes para el receptor, alineación y estados válidos para todos los subobjetos heredados. Eso es un límite inferior de almacenamiento observado, no un sizeof reconstruido. CPed::constructor debe establecer punteros y estado requeridos por las operaciones posteriores.

El receptor devuelve por 00817F20 debe ser no nulo para las escrituras incondicionales a p+60+3D4 y p+60+416. Las ramas que convierten un puntero nulo a cero terminan igualmente escribiendo a direcciones bajas; son comportamiento original, no comprobaciones que permitan ejecutar el constructor con un objeto vacío.

Los punteros this+21C y this+224 deben referirse a objetos vivos y suficientemente grandes. Los imports, globales, subsistemas, callbacks y estados del juego deben estar inicializados. Las llamadas intermedias pueden modificar this+228 y globales, por lo que las lecturas posteriores deben repetirse en el mismo orden.

La sección x87 conserva el control word salvo las excepciones que interrumpan la ejecución. No se sustituye por cast C++: precisión extendida, redondeos sucesivos, máscara de excepciones y resultado indefinido/indefinite de FISTP necesitan validación de máquina. En MSVC x86, long double de C++ no garantiza el mismo contrato.

No se llama al constructor original en las pruebas existentes ni se reemplaza su dirección. Ningún wrapper de este documento cuenta como reconstrucción completa.

## Contraste con análisis fresco

El pseudocódigo fresco `evidence/rea-deep-0.json` concuerda con el orden y campos del constructor. La referencia real es un tail jump desde `0x0096D881`, dentro del wrapper `0x0096D870`, después de obtener almacenamiento mediante `0x0096D520`. El escaneo previo buscó CALL rel32; no incluía tail JMP y no negaba este consumidor.

La entrada `0x00D0D21A` contiene la rutina CRT rand: el estado por hilo obtenido mediante `0x00D18B56` se actualiza con `state * 0x343FD + 0x269EC3`, y devuelve `(state >> 16) & 0x7FFF`. El import `0x00D4D4B8` es USER32.dll!SendMessageA. Los valores canónicos de constantes son `2^-15`, `-140000.0`, `200.0`, `30.0` y `2.0`; constan en el ledger. El ROUND del descompilador no contradice la instrucción FLDCW de truncamiento ni sustituye su contrato.

## Implementación y comparación del cuerpo

`source/game/Peds/CPlayerPed.h` implementa el cuerpo con callbacks explícitos para dependencias y acceso a globales. El helper de aritmética flotante usa las instrucciones x87 FILD, FMUL, FNSTCW, FLDCW y FISTP de 64 bits con restauración del control word, sin aproximar con long double.

Pasaron 49.152 comparaciones Win32 contra los 884 bytes originales completos, con 18 llamadas directas y un import sustituidos. El banco prueba 1.024 combinaciones de condiciones, doce control words (tres precisiones por cuatro redondeos, excepciones enmascaradas) y cuatro valores de rand. Compara cinco buffers de 4.096 bytes, 28 globales, orden/receptores/argumentos de dependencias, retorno y status/control word x87. Incluye una constante float con NaN señalizante para la secuencia de FLD/FSTP. Evidencia: `constructor-validation-summary.json` y `constructor-fixture.json`; repetir con `constructor-check.cpp`.

Esta validación cubre el algoritmo del constructor con contratos aislados. Los callbacks de acceso a globales y direcciones deben ser accesos puros sin efectos sobre otros campos ni estado flotante; los callbacks de callees pueden modificar estado. Los punteros dependientes nulos que conducirían a escrituras de memoria baja quedan fuera de las precondiciones válidas y no se ejecutan. El constructor original no se invocó sobre el jugador vivo ni se instaló su reemplazo.
