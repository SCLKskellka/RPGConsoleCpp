//
// Created by c.barrera on 23/10/2025.
//

#pragma once
#include <string>
#include "Item.h"
#include "Player.h"


class Potion : public Item {
    public:
    Potion(std::string name,int healAmount) : Item(name) {
        _healAmount = healAmount;
    }

    ~Potion() = default;
    void Effect(const std::shared_ptr<Character> &player) override;
    private:
    int _healAmount;
};
