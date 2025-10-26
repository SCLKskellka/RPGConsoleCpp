//
// Created by c.barrera on 21/10/2025.
//

#include "Character.h"
#include "Player.h"
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
    std::cout << std::endl<< std::endl;
    std::cout << "{| "<< _characterName << "  [Lvl-" << _lvl << "] |}" << std::endl;
    std::cout << ">> HP: "<< _characterHP << "/" << _characterHPMax << std::endl;
    std::cout << "<Power> "<< _power << std::endl;
    std::cout << "<Armor> "<< _armor << std::endl;
    std::cout << std::endl<< std::endl;
}


void Character::Attack(Character target) const {
    target.TakeDamage(_power);
}

void Character::TakeDamage(int damage) {
    damage -= _armor;
    _characterHP -= damage;
    if (_characterHP <= 0) {
        _characterHP = 0;
        _isDead = true;
    }
}

void Character::Healing(int healAmount) {
    _characterHP += healAmount;
    if (_characterHP > _characterHPMax) {
        _characterHP = _characterHPMax;
    }
}

bool Character::IsDead() const {
    return _isDead;
}

int Character::GetPower() const {return _power;}

void Character::Growth(int growAmount) {
    _xp += growAmount;
    while (_xp >= _maxXP){
        _lvl += 1;
        _power += 3;
        _armor += 1;
        _characterHPMax += 5;
        _characterHP += 5;
        _xp-=_maxXP;
    }
}

