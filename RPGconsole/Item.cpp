//
// Created by c.barrera on 23/10/2025.
//

#include <utility>
#include "Item.h"

class Player;//prévient l'utilisation de la class

Item::Item(std::string name) {
    _itemName = std::move(name);
}

std::string Item::GetName() {
    return _itemName;
}

void Item::Effect(Player &player) {
    std::cout << "Nothing "  << player.IsDead() << "\n";
}