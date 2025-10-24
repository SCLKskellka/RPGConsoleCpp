//
// Created by c.barrera on 23/10/2025.
//

#pragma once
#include <vector>
#include "Item.h"

class Item;

class Inventory {
public:
    Inventory() = default;
    ~Inventory() = default;
    void AddItem(const std::shared_ptr<Item> &item);// smart pointeur en const pour permettre le polymorphism
    void RemoveItem(const std::shared_ptr<Item> &item);// smart pointeur en const pour permettre le polymorphism
    void Display();

    std::shared_ptr<Item> GetItem(int position);
    int GetInventorySize();

private:
    std::vector<std::shared_ptr<Item>> _items;
};
