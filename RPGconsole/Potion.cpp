//
// Created by c.barrera on 23/10/2025.
//

#include "Potion.h"
#include "Player.h"
void Potion::Effect(const std::shared_ptr<Character> &player) {
    player->Healing(15);
}

