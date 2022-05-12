cmake_minimum_required(VERSION 3.16)
project(TP_v2)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/main.cpp
        src/Game.cpp
        src/BasicDrawable.cpp
        include/BasicDrawable.h
        include/structs/Vector2.h
        include/structs/Rect.h
        src/SFMLDrawable.cpp
        include/SFMLDrawable.h
        src/TextureManager.cpp
        include/TextureManager.h
        src/BasicAnimated.cpp
        include/BasicAnimated.h
        src/TableAnimated.cpp
        include/TableAnimated.h
        include/BasicEntity.h
        src/PhysicalEntity.cpp
        include/PhysicalEntity.h
        src/MainCharacter.cpp
        include/MainCharacter.h
        src/MainCharacterBuilder.cpp
        include/MainCharacterBuilder.h
        src/ObjectHandler.cpp
        include/ObjectHandler.h
        include/BasicWindowHandler.h
        src/SFMLWindowHandler.cpp
        include/SFMLWindowHandler.h src/BasicWindowHandler.cpp src/BasicEventHandler.cpp include/BasicEventHandler.h src/SFMLEventHandler.cpp include/SFMLEventHandler.h src/MapDrawer.cpp include/SFMLMapHandler.h include/MapDrawer.h src/SFMLMapHandler.cpp src/CSVMapLoader.cpp include/CSVMapLoader.h src/BasicMapHandler.cpp include/BasicMapHandler.h include/PhysicsEngine.h src/PhysicsEngine.cpp src/Enemy.cpp include/Enemy.h include/EnemyBuilder.h src/EnemyBuilder.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(MainBuild ${SOURCES})
target_link_libraries(MainBuild sfml-graphics sfml-audio sfml-system)
target_include_directories(MainBuild PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(MainBuild PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(DIRECTORY resources DESTINATION
        ${PROJECT_BINARY_DIR})