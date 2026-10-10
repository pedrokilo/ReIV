"""Organize existing GTA IV headers using GTA V's directory vocabulary only."""
import csv
import hashlib
import importlib.util
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REFERENCE = Path("E:/Original/gta5/src/dev_ng/game")
HERE = Path(__file__).resolve().parent


def classify(name):
    n = name.split("::")[0].split("<")[0]
    if n.startswith(("CNet", "CParse", "CMsg", "Msg")) or n.endswith(("ArrayHandler", "Event")) and not n.startswith(("CEvent", "CInform", "CIntermezzo", "CMovement")):
        if n.endswith("ArrayHandler") or "NetworkArray" in n or "NetworkArrayHandler" in n: return "network/Arrays"
        if n.startswith(("CNetObj", "CParse", "CNetworkObject", "CNetClone", "CNetBlender", "CNetworkBlender")): return "network/Objects"
        if n.endswith("Event") or "NetworkEvent" in n: return "network/Events"
        if "Voice" in n: return "network/Voice"
        if "PlayerInfo" in n: return "network/Players"
        return "network/General"
    if n.startswith("CTask") or n.endswith(("TaskInfo", "TaskInfoBase")) or n in {"CTargetTaskInfo", "CMedicTaskInfo", "CMeleeTaskInfo", "CSequenceTaskInfo", "CJackTaskInfo"} or re.match(r"C(Simple|Complex|Status|Scenario|PlayRandom|Sit|Stand|Die|Dead).*Info$", n) or n.startswith("CDummyTask"):
        if re.search("Medic|FireTruck|WaterCannon|TreatAccident|AssessInjured", n): return "task/Service"
        if re.search("Arrest|Cop|Criminal|Steal|Bomb", n): return "task/Crimes"
        if re.search("Car|Vehicle|Drive|Driving|Boat|Helicopter|Seat|Shunt|AutoDriver", n): return "task/Vehicle"
        if re.search("Combat|Melee|Cover|Guard|Gang|Destroy", n): return "task/Combat"
        if re.search("Gun|Weapon|Projectile|Reload|Grenade", n): return "task/Weapons"
        if re.search("NM|Fall|GetUp|InAir|Balance|Water|BlendFrom", n): return "task/Physics"
        if re.search("Anim|LookAt|Signal", n): return "task/Animation"
        if re.search("Scenario|Attractor|Ambient", n): return "task/Scenario"
        if re.search("Flee|React|Hit|Die|Dead|Injured|Revive|Fire|Cower|Shocking|Duck|HandsUp", n): return "task/Response"
        if re.search("Move|GoTo|Seek|Wander|Follow|Climb|Jump|Swim|Run|Slide|Turn|Route|Pathfind|Step|Patrol", n): return "task/Movement"
        if n in {"CTask", "CTaskSimple", "CTaskComplex", "CTaskList", "CTaskSet", "CWeightedTaskSet", "CTaskInfo", "CTaskInfoWithCloneTask", "CTaskMoveInterface"}: return "task/System"
        if re.search("None|DoNothing|Pause|StandStill", n): return "task/Default"
        return "task/General"
    if n.startswith(("CEvent", "CInform", "CMovementEventHandler")): return "event/system" if re.search("Handler|Scanner|Factory|Group", n) else "event"
    if n.startswith("aud") or n == "CAudioAttr": return "audio"
    if n.startswith("CCamScript") or n == "CCamScripted": return "camera/scripted"
    if n.startswith("CIntermezzo") or "Cinematic" in n or n == "CCamIntermezzo": return "camera/cinematic"
    if n.startswith("CCamCutscene"): return "camera/cutscene"
    if n.startswith("CCamReplay"): return "camera/replay"
    if n.startswith("CCamDebug"): return "camera/debug"
    if n.startswith("CCam"): return "camera/base" if n in {"CCam", "CCamInterp", "CCamShake", "CCamHistory", "CCamTrans", "CCamFinal"} else "camera/gameplay"
    if n.startswith("CViewport"): return "camera/viewports"
    if "ModelInfo" in n and not n.endswith("DC"): return "modelinfo"
    if n.startswith(("cr", "CAnim", "CAtdNodeAnim")): return "animation"
    if n.startswith(("CIk", "CSimpleIk")): return "ik"
    if "Formation" in n or n.startswith("CPedGroup"): return "PedGroup"
    if "MoveBlend" in n: return "Peds/PedMoveBlend"
    if "Intelligence" in n or n.endswith("Scanner") or "SeekPosCalculator" in n or "Targetting" in n: return "Peds/PedIntelligence"
    if n.startswith(("CPed", "CPlayerPed", "CDummyPed")): return "Peds"
    if n.startswith(("CVehicle", "CAutomobile", "CHeli", "CTrain", "CPlane", "CBike", "CBoat")) or n == "rmcInstanceWheelData": return "Vehicles"
    if n.startswith("CCutscene"): return "Cutscene"
    if n in {"CObject", "CDummyObject"}: return "Objects"
    if n in {"CEntity", "CDynamicEntity", "CPhysical", "CVirtualBase", "CBuilding", "CAnimatedBuilding"}: return "scene/entities"
    if "Portal" in n or n == "CInteriorInst": return "scene/portals"
    if n.startswith(("CLoader", "fiStreaming")): return "streaming"
    if n.startswith(("GtaThread", "CScript", "CMissionCleanup")): return "script"
    if n.startswith("CPlayStat"): return "Stats"
    if n.startswith("CReplay"): return "control/replay"
    if n.startswith(("UI", "CHtml", "Html", "WebBrowser", "SocialWebBrowser", "CFont", "CScrollBar")): return "frontend/html" if "Html" in n or "Browser" in n else "frontend"
    if n.startswith(("ph", "fragInst", "ARTFeedback", "Collision", "Discrete", "PointCollector", "Continuous", "Convex", "Triangle", "Minkowski", "bt", "gtaFrag")): return "physics"
    if n.startswith(("CCustomShader", "CShader")): return "shaders"
    if n.startswith("CRenderPhase"): return "renderer/RenderPhases"
    if n.startswith(("CDraw", "CDataBlockDC", "CNewDraw", "CEndDraw", "CBaseDC")) or n.endswith("DC"): return "renderer/DrawLists"
    if n.startswith(("T_CB", "T_Set")): return "renderer/Util"
    if n.startswith(("CSet", "CGrc", "CRAGE", "CLockRender", "CUnLockRender", "CInsertEnd", "CAddTxd", "CAddModel", "CSetupDef", "CClearRender", "CCreateRender", "CUseLights", "CSmashMan", "gtaDrawable")): return "renderer"
    if n.endswith("Attr") or n.startswith(("CPrt", "C2dEffect")): return "vfx/metadata"
    if n in {"CInterpolator", "CVehInterp", "CPedInterp", "CObjInterp", "CAtdNodeFrameAddress"}: return "control/replay"
    if n.startswith("atSingleton"): return "templates"
    if n in {"CLadderInfo", "CSpawnPoint"}: return "scene/world"
    return "system"


def main():
    if (HERE / "game-folders.csv").exists():
        raise RuntimeError("Already organized; use generate-class-headers.py to verify or regenerate.")
    entries = list(csv.DictReader((ROOT / "source/class-files.csv").open(encoding="utf-8")))
    references = defaultdict(set)
    for path in REFERENCE.rglob("*.h"):
        rel = path.relative_to(REFERENCE)
        if any(part.lower().startswith(("vs_project", "test_ignore")) for part in rel.parts): continue
        references[path.stem.casefold()].add(rel.parent.as_posix())
    mapping, moves, counts = [], [], Counter()
    for entry in entries:
        if not entry["file"].startswith("source/game/"): continue
        name = entry["name"]
        base = name.split("::")[0].split("<")[0]
        matches = references.get(base.casefold(), set()) | references.get((base[1:] if base.startswith("C") else base).casefold(), set())
        folder = classify(name)
        # Use a unique filename match only within the inferred subsystem.
        compatible = {m for m in matches if m.split("/")[0].lower() == folder.split("/")[0].lower()}
        evidence = "name_family"
        if len(compatible) == 1:
            folder = next(iter(compatible)); evidence = "reference_filename"
        mapping.append({"name": name, "folder": folder, "basis": evidence})
        source = (ROOT / entry["file"]).resolve()
        destination = (ROOT / "source/game" / folder / Path(entry["file"]).relative_to("source/game")).resolve()
        workspace = (ROOT / "source/game").resolve()
        assert source.is_relative_to(workspace) and destination.is_relative_to(workspace)
        assert source.is_file() and not destination.exists(), (source, destination)
        moves.append((source, destination, hashlib.sha256(source.read_bytes()).hexdigest()))
        counts[folder] += 1
    with (HERE / "game-folders.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=["name", "folder", "basis"])
        writer.writeheader(); writer.writerows(mapping)
    for source, destination, digest in moves:
        destination.parent.mkdir(parents=True, exist_ok=True)
        source.rename(destination)
        assert hashlib.sha256(destination.read_bytes()).hexdigest() == digest
    # Remove only empty old owner directories, confined to source/game.
    for directory in sorted((ROOT / "source/game").rglob("*"), key=lambda p: len(p.parts), reverse=True):
        if directory.is_dir() and not any(directory.iterdir()): directory.rmdir()
    spec = importlib.util.spec_from_file_location("headers", HERE / "generate-class-headers.py")
    module = importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
    module.main()
    print(f"Moved {len(moves)} headers; content hashes preserved.")
    print(dict(sorted(counts.items())))


if __name__ == "__main__": main()
