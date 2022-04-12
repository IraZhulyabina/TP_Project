//
// Created by profidoc on 08.04.2022.
//

#pragma once
#include "resources/headers/Kinematics.h"
#define MySuperFile "/home/profidoc/ClionProjects/semestr2/TP/resources/textures/characters_stay.png"
// TODO: сделать нормальную загрузку этих данных из файла
namespace TexturePackResources {

enum TileSetNames {
  Enemy,
  Player,
  Nothing
};

const std::map<TileSetNames, std::string> filenames_map = {
    {TileSetNames::Enemy, MySuperFile},
    {TileSetNames::Player, MySuperFile}
};

const std::map<TileSetNames, Rect2u> sub_tables_map = {
    {TileSetNames::Enemy, {0, 5, 3, 5}},
    {TileSetNames::Player, {0, 0, 3, 5}},
};

const std::map<std::string, Coord2u> tables_map = {
    {MySuperFile, {12, 10}}
};

const std::vector<std::string> filenames {
    MySuperFile
};

const std::map<kinematics::Orientation, uint32_t> moving_states = {
    {kinematics::Stay, 0},
    { kinematics::Down, 1},
    {kinematics::Left, 2},
    {kinematics::Right, 3},
    {kinematics::Up, 4}
};

const float kNormalFramesPerSecond = 3.0;

}