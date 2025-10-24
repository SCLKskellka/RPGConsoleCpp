//
// Created by c.barrera on 23/10/2025.
//

#pragma once
#include <memory>
#include <string>

#include "Player.h"

class Player;//prévient l'utilisation de la class
class Character;

class Item {
public:
    Item(std::string name);
    virtual ~Item() = default;
    std::string GetName();
    virtual void Effect(const std::shared_ptr<Character> &character);// smart pointeur en const pour permettre le polymorphism

protected:
    std::string _itemName;
};
