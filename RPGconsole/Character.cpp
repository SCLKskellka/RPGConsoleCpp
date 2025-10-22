//
// Created by c.barrera on 21/10/2025.
//

#include "Character.h"

#include <utility>
Character::Character(std::string characterName,const int hPMax, const int power, const int armor) {
    _characterName = std::move(characterName);
    _characterHPMax = hPMax;
    _characterHP = hPMax;
    _power = power;
    _armor = armor;
}

Character::~Character() = default;

void Character::Display() {
    std::cout << "[[ "<< _characterName << " ]]" << std::endl;
    std::cout << ">> HP: "<< _characterHP << "/" << _characterHPMax << std::endl;
    std::cout << "<Power> "<< _power << std::endl;
    std::cout << "<Armor> "<< _armor << std::endl;
}


void Character::Attack(Character target) const {
    target.TakeDamage(_power);
}


void Character::TakeDamage(const int Damage) {
    _characterHP -= Damage;
    if (_characterHP <= 0) {
        _isDead = true;
    }
}
bool Character::IsDead() const {
    return _isDead;
}
int Character::GetPower() const {return _power;}

