//
// Created by c.barrera on 21/10/2025.
//

#pragma once
#include <iostream>
#include <memory>


class Character {
    public:
    Character(std::string characterName, int hPMax, int power, int armor);

    virtual ~Character();

    void Display();
    void TakeDamage(int Damage);
    void Attack(Character target) const;
    [[nodiscard]] bool IsDead() const;
    [[nodiscard]] int GetPower() const;

    protected:
    std::string _characterName;
    int _characterHP;
    int _characterHPMax;
    int _power;
    int _armor;
    bool _isDead = false;
};
