//
// Created by profidoc on 06.05.22.
//

#include "MainCharacterBuilder.h"
MainCharacter MainCharacterBuilder::Build(sf::RenderWindow& window,
                                          TextureManager& texture_manager) {
  MainCharacter main_character;
  main_character.SetWindow(&window);
  auto texture =
      texture_manager.GetTexture(kMainCharacterFilename);
  main_character.SetTexture(texture);
  main_character.SetTextureRect(Rect2i(0, 0,
                                       kPlayerTileShape.x,
                                       kPlayerTileShape.y));
  main_character.SetPosition(kPLayerInitialPosition);
  main_character.SetState(MainCharacter::PlayerStates::Stay);

  main_character.SetFramesNum(kPlayerTilesetRawLength);
  main_character.SetTileShape(kPlayerTileShape);
  main_character.SetPhysicalShape(kPlayerTileShape);
  main_character.SetFramesPerSecond(kPlayerFPS);
  main_character.SetAnchorCoords({0, 0});

  return main_character;
}