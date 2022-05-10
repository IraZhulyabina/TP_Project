//
// Created by profidoc on 07.05.22.
//
#pragma once
#include "ObjectHandler.h"
void ObjectHandler::InitMainCharacter(sf::RenderWindow& window,
                                      TextureManager& texture_manager) {
  main_character_ = MainCharacterBuilder::Build(window, texture_manager);
}

void ObjectHandler::InitEnemies(sf::RenderWindow& window, TextureManager& texture_manager,
                                std::vector<Rect2f>* solids) {
  for (uint32_t i = 0; i < kNumberOfEnemies; ++i) {
    Enemy enemy = EnemyBuilder::Build(window, texture_manager, solids, main_character_);
    enemy.SetID(i);
    enemies_.emplace_back(enemy);
  }
}

void ObjectHandler::Init(sf::RenderWindow& window, TextureManager& texture_manager,
                         std::vector<Rect2f>* solids) {
  InitMainCharacter(window, texture_manager);
  InitEnemies(window, texture_manager, solids);
}

MainCharacter& ObjectHandler::GetMainCharacter() {
  return main_character_;
}

void ObjectHandler::DrawTargets() {
  main_character_.Draw();
  for (auto& enemy : enemies_) {
    enemy.Draw();
  }
}

const float ObjectHandler::kInitialPlayerBasicSpeed = 200.0;

float ObjectHandler::GetPlayerBasicSpeed() const { return player_basic_speed_; }

void ObjectHandler::UpdateGraphics(uint64_t elapsed_time) {
  main_character_.UpdateAnimation(elapsed_time);
  for (auto& enemy : enemies_) {
    enemy.UpdateAnimation(elapsed_time);
  }
}
std::vector<Enemy>& ObjectHandler::GetEnemies() { return enemies_; }
