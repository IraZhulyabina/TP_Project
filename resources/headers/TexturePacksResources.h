//
// Created by profidoc on 08.04.2022.
//

#pragma once
#define MySuperFile "/home/profidoc/ClionProjects/semestr2/TP/resources/textures/characters.png"
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
    {TileSetNames::Enemy, {0, 4, 3, 4}},
    {TileSetNames::Player, {0, 0, 3, 4}},
};

const std::map<std::string, Coord2u> tables_map = {
    {MySuperFile, {12, 8}}
};

const std::vector<std::string> filenames {
    MySuperFile
};

const float kNormalFramesPerSecond = 3.0;

}