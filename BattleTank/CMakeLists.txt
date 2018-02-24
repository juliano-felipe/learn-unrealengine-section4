cmake_minimum_required (VERSION 2.6)
project (UE4)
set(CMAKE_CXX_STANDARD 11)

include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/IncludeDirectories.cmake")
include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/Definitions.cmake")
include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/UE4Editor.cmake")

set(MONO_ROOT_PATH "C:/Program Files/Epic Games/UE_4.17/Engine/Binaries/DotNET")
set(BUILD cd /d "${MONO_ROOT_PATH}")

# Custom target for UE4Editor project, Development configuration
add_custom_target(UE4Editor-Development ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -game -progress)
add_custom_target(UE4Editor-Development-CLEAN ${BUILD} && UnrealBuildTool.exe UE4Editor Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -clean)

include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/UE4Game.cmake")

# Custom target for UE4Game project, Development configuration
add_custom_target(UE4Game-Development ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -game -progress)
add_custom_target(UE4Game-Development-CLEAN ${BUILD} && UnrealBuildTool.exe UE4Game Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -clean)

include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/BattleTank.cmake")

# Custom target for BattleTank project, Development configuration
add_custom_target(BattleTank-Development ${BUILD} && UnrealBuildTool.exe BattleTank Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -game -progress)
add_custom_target(BattleTank-Development-CLEAN ${BUILD} && UnrealBuildTool.exe BattleTank Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -clean)

include("E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/Intermediate/ProjectFiles/BattleTankEditor.cmake")

# Custom target for BattleTankEditor project, Development configuration
add_custom_target(BattleTankEditor-Development ${BUILD} && UnrealBuildTool.exe BattleTankEditor Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -game -progress)
add_custom_target(BattleTankEditor-Development-CLEAN ${BUILD} && UnrealBuildTool.exe BattleTankEditor Win64 Development -project="E:/workspace/learn/unrealenginecourse/Section_04/BattleTank/BattleTank.uproject" -clean)

add_executable(PleaseIgnoreMe ${BattleTankEditor_FILES})