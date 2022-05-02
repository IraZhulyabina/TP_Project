//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "resources/headers/Kinematics.h"

#define CharFile "textures/characters_stay.png"
#define MapGrassFile "textures/MapTexture/TX_Tileset_Grass.png"
#define MapWallsFile "textures/MapTexture/TX_Tileset_Wall.png"


// TODO: сделать нормальную загрузку этих данных из файла
namespace TexturePackResources {
enum TileSetNames {
  Enemy,
  Player,
  Nothing,
  MapGrass,
  MapWalls
};

const std::map<TileSetNames, std::string> filenames_map = {
    {TileSetNames::Enemy, CharFile},
    {TileSetNames::Player, CharFile},
    {TileSetNames::MapGrass, MapGrassFile},
    {TileSetNames::MapWalls, MapWallsFile}
};

const std::map<TileSetNames, Rect2u> sub_tables_map = {
    {TileSetNames::Enemy, {0, 5, 3, 5}},
    {TileSetNames::Player, {0, 0, 3, 5}},
    {TileSetNames::MapGrass, {0, 0, 8, 8}},
    {TileSetNames::MapWalls, {0, 0, 16, 16}}
};

const std::map<std::string, Coord2u> tables_map = {
    {CharFile, {12, 10}},
    {MapGrassFile, {8, 8}},
    {MapWallsFile, {16, 16}}
};

const std::vector<std::string> filenames {CharFile, MapGrassFile, MapWallsFile};

const std::map<kinematics::Orientation, uint32_t> moving_states = {
    {kinematics::Stay, 0},
    { kinematics::Down, 1},
    {kinematics::Left, 2},
    {kinematics::Right, 3},
    {kinematics::Up, 4}
};

const float kNormalFramesPerSecond = 3.0;

}