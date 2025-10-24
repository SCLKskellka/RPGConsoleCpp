//
// Created by c.barrera on 22/10/2025.
//

#pragma once

#include <memory>
#include "Character.h"
#include "Player.h"


class Enemy:public Character{
    public:
    Enemy(const std::string &characterName, int hPMax, int power, int armor, int growValue, int lvl);
    ~Enemy() override;
    void TakeDamageFromPlayer(int &damage, Player &player);
    void SetGrowValue(int &growValue);
    int GetGrowValue() const;
    private:
    int _growValue;
};
