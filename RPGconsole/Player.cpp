//
// Created by c.barrera on 21/10/2025.
//

#include "Player.h"
#include <iostream>

Player::Player(const std::string &characterName, const int hPMax, const int power, const int armor)
    : Character( characterName,hPMax, power, armor) {
}

Player::~Player() = default;
