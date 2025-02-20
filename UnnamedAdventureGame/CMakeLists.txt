# Game cmake

add_executable(UnnamedAdventureGame main.cpp "Scenes/MainMenuScene.cpp" "Components/Transformator.h" "Components/Transformator.cpp" "Components/InfoUI.cpp" "Components/InfoUI.h" "Components/FreeCamMovement.h" "Components/FreeCamMovement.cpp" "Components/WindowManager.cpp" "Components/WindowManager.h" "Components/AudioTester.h" "Components/AudioTester.cpp")

# Copies used for .exe
add_custom_command(TARGET UnnamedAdventureGame PRE_LINK
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${FMOD_DLL_DIR} $<TARGET_FILE_DIR:UnnamedAdventureGame>
    COMMENT "Copying FMOD DLL..."
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PHYSX_DLL_DIR} $<TARGET_FILE_DIR:UnnamedAdventureGame>
    COMMENT "Copying PHYSX DLL..."
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PHYSX_COMMON_DLL_DIR} $<TARGET_FILE_DIR:UnnamedAdventureGame>
    COMMENT "Copying PHYSX COMMON DLL..."
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PHYSX_COOKING_DLL_DIR} $<TARGET_FILE_DIR:UnnamedAdventureGame>
    COMMENT "Copying PHYSX COOKING DLL..."
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PHYSX_FOUNDATION_DLL_DIR} $<TARGET_FILE_DIR:UnnamedAdventureGame>
    COMMENT "Copying PHYSX FOUNDATION DLL..."
    COMMAND ${CMAKE_COMMAND} -E copy_directory  ${DATA_FILES} ${DESTINATION_COPY}
    COMMENT "Copying DATA..."
)