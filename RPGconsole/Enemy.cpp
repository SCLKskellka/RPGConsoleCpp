//
// Created by c.barrera on 22/10/2025.
//

#include "Enemy.h"

Enemy::Enemy(const std::string &characterName, const int hPMax, const int power, const int armor, int growValue, int lvl)
    : Character( characterName,hPMax, power, armor) {
    _growValue = growValue;
    _lvl = lvl;
}

Enemy::~Enemy() = default;

void Enemy::TakeDamageFromPlayer(int &damage, Player &player) {
    damage -= _armor;
    _characterHP -= damage;
    if (_characterHP <= 0) {
        _isDead = true;
        player.Growth(_growValue);
    }
}

void Enemy::SetGrowValue(int &growValue) {
    _growValue = growValue;
}

int Enemy::GetGrowValue() const {
    return _growValue;
}





