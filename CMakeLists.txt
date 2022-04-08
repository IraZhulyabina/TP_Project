cmake_minimum_required(VERSION 3.21)
project(TP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        sources/Game.cpp
        sources/Handlers/EventHandler.cpp
        sources/Handlers/ObjectHandler.cpp
        sources/Handlers/MapHandler.cpp
        sources/drawing/Drawer.cpp
        sources/drawing/Drawable.cpp
        sources/Handlers/PhysicsEngine.cpp
        sources/Creators/Creator.cpp
        sources/Creators/ButtonCreator.cpp
        sources/Creators/ChestCreator.cpp
        sources/Creators/EnemyCreator.cpp
        sources/Creators/MainCharacterCreator.cpp
        sources/Entities/Entity.cpp
        sources/Entities/Button.cpp
        sources/Entities/Chest.cpp
        sources/Entities/MainCharacter.cpp
        sources/Entities/Enemy.cpp
        sources/Entities/Physics.cpp
        sources/Handlers/WindowHandler.cpp
        sources/drawing/TileSet.cpp include/drawing/TexturePack.cpp include/drawing/TexturePack.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(MainBuild ${SOURCES})
target_link_libraries(MainBuild sfml-graphics sfml-audio)
target_include_directories(MainBuild PRIVATE ${PROJECT_SOURCE_DIR})