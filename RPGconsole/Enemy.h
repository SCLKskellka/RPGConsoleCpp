//
// Created by c.barrera on 22/10/2025.
//

#pragma once
#include <memory>

#include "Character.h"


class Enemy:public Character{
    public:
    Enemy(const std::string &characterName, int hPMax, int power, int armor);
    ~Enemy() override;
    void TakeDamage(int &damage, const std::shared_ptr<Character> &character);

};
