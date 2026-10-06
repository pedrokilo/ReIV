# Organización del código de ReIV

La plantilla parte de IV-SDK: sus headers describen clases del juego y RAGE, `Scripting` agrupa los natives y `injector` implementa la infraestructura de hooks. ReIV distribuye las implementaciones propias por su función:

```text
source/
├── core/
│   └── ReIV.cpp                  Entrada del ASI y eventos de inicio
├── rage/
│   └── AtStringHash.h            Primera función reconstruida del motor
├── game/                        Futuras clases y sistemas de GTA IV
├── Scripting/                   Futuras reconstrucciones de scripting
└── hooks/
    ├── AtStringHashProbe.h       Banco, trampoline y conexión del hook
    └── AtStringHashSignature.h   Identificación del original canónico
```

`game` y `Scripting` se conservan en Git mediante `.gitkeep`. Las clases y natives de referencia permanecen en `contrib/IV SDK/IV-SDK-main/include`; la infraestructura de terceros sigue en su carpeta `injector`. Se añaden a `source` implementaciones propias conforme se identifiquen y reconstruyan.
