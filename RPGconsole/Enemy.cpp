//
// Created by c.barrera on 22/10/2025.
//

#include "Enemy.h"

Enemy::Enemy(const std::string &characterName, const int hPMax, const int power, const int armor)
    : Character( characterName,hPMax, power, armor) {
}

Enemy::~Enemy() = default;

void Enemy::TakeDamage(int &damage) {
    damage -= _armor;
    _characterHP -= damage;
    if (_characterHP <= 0) {
        _isDead = true;

    }
}




