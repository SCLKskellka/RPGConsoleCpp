//
// Created by c.barrera on 21/10/2025.
//

#pragma once
#include "Character.h"


class Player:public Character {
    public:
    Player(const std::string &characterName, int hPMax, int power, int armor);
    ~Player() override;

};