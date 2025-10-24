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
    std::cout << "[[ "<< _characterName << " ]]" << std::endl;
    std::cout << ">> HP: "<< _characterHP << "/" << _characterHPMax << std::endl;
    std::cout << "<Power> "<< _power << std::endl;
    std::cout << "<Armor> "<< _armor << std::endl;
}


void Character::Attack(Character target) const {
    target.TakeDamage(_power);
}

void Character::TakeDamage(int damage) {
    damage -= _armor;
    _characterHP -= damage;
    if (_characterHP <= 0) {
        _isDead = true;
    }
}

void Character::Healing(int healAmount) {
    _characterHP += healAmount;
}

bool Character::IsDead() const {
    return _isDead;
}

int Character::GetPower() const {return _power;}

