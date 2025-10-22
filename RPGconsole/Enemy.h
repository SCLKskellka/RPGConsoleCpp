//
// Created by c.barrera on 22/10/2025.
//

#pragma once
#include "Character.h"


class Enemy : public Character{
    public:
    Enemy(const std::string &characterName, int hPMax, int power, int armor);
    ~Enemy() override;

};
