//
// Created by c.barrera on 21/10/2025.
//

#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Item.h"

class Item;//prévient l'utilisation de la class
class Inventory;//prévient l'utilisation de la class

class Player : public Character {
public:
    Player(const std::string &characterName, int hPMax, int power, int armor);
    ~Player() override;
    void Display() override;
    void LootItem(const std::shared_ptr<Item> &item);// smart pointeur en const pour permettre le polymorphism
    void DropItem(const std::shared_ptr<Item> &item);// smart pointeur en const pour permettre le polymorphism
    void DisplayInventory();
    int GetInventorySize();
    void UseItem(int position);
private:
    std::unique_ptr<Inventory> _playerInventory;
};
