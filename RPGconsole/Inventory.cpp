//
// Created by c.barrera on 23/10/2025.
//
#include <memory>
#include "Inventory.h"

void Inventory::AddItem(const std::shared_ptr<Item> &item) {
    _items.push_back(item);
}

void Inventory::RemoveItem(const std::shared_ptr<Item> &item) {
    for (int i = 0; i < _items.size(); i++) {
        if (_items[i]->GetName() == item->GetName()) {
            _items.erase(_items.begin() + i);
        }
    }
}

void Inventory::Display() {
    std::cout << "=-=-=-=-=-=-=-=[ Inventaire ]-=-=-=-=-=-=-=-="<< std::endl;
    for (int i = 0; i < _items.size(); i++) {
        std::cout << "{" << i << "}" << _items[i]->GetName() << std::endl;
    }
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<< std::endl;
}

std::shared_ptr<Item> Inventory::GetItem(int position) {
    return _items[position];
}

int Inventory::GetInventorySize() {
    return _items.size();
}

