//
// Created by c.barrera on 23/10/2025.
//

#include "Potion.h"
#include "Player.h"
void Potion::Effect(Player &player) {
    player.Healing(15);
}

