//
// Created by c.barrera on 23/10/2025.
//

#pragma once
#include "Wave.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    Game() = default;
    ~Game() = default;

    void Menu();
    void NewPlayerCharacter();

    Wave<Enemy> FirstWaveCreator();
    Wave<Enemy> SecondWaveCreator();
    void Adventure(Player &player);
    void Battle(int id, Player &player);
    void Inventory(const int &id,Player &player);
};
