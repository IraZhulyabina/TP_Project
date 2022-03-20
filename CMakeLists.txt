cmake_minimum_required(VERSION 3.21)
project(TP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        sources/main.cpp
        sources/Game.cpp include/Game.h
        sources/Handlers/EventHandler.cpp include/Handlers/EventHandler.h
        sources/Handlers/ObjectHandler.cpp include/Handlers/ObjectHandler.h
        sources/Handlers/MapHandler.cpp include/Handlers/MapHandler.h
        sources/Handlers/Drawer.cpp include/Handlers/Drawer.h
        sources/Handlers/PhysicsEngine.cpp
        include/Handlers/PhysicsEngine.h
        sources/Creators/Creator.cpp include/Creators/Creator.h
        sources/Creators/ButtonCreator.cpp include/Creators/ButtonCreator.h
        sources/Creators/ChestCreator.cpp include/Creators/ChestCreator.h
        sources/Creators/EnemyCreator.cpp include/Creators/EnemyCreator.h
        sources/Creators/MainCharacterCreator.cpp include/Creators/MainCharacterCreator.h
        sources/Entities/Entity.cpp include/Entities/Entity.h
        sources/Entities/Button.cpp include/Entities/Button.h
        sources/Entities/Chest.cpp include/Entities/Chest.h
        sources/Entities/MainCharacter.cpp include/Entities/MainCharacter.h
        sources/Entities/Enemy.cpp include/Entities/Enemy.h
        sources/Entities/Physics.cpp sources/Entities/Physics.h sources/Handlers/WindowHandler.cpp include/Handlers/WindowHandler.h include/main.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(MainBuild ${SOURCES})
target_link_libraries(MainBuild sfml-graphics sfml-audio)