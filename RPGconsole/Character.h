//
// Created by c.barrera on 21/10/2025.
//

#pragma once
#include <iostream>

class Character {
public:
    Character(std::string characterName, int hPMax, int power, int armor);
    virtual ~Character();
    virtual void Display();
    void TakeDamage(int damage);
    void Healing(int healAmount);
    void Attack(Character target) const;
    [[nodiscard]] bool IsDead() const;
    [[nodiscard]] int GetPower() const;
    void Growth(int growAmount);

protected:
    std::string _characterName;
    int _characterHP;
    int _characterHPMax;
    int _power;
    int _armor;
    bool _isDead = false;
    int _xp = 0;
    int _lvl = 1;
    int _maxXP;

};
