//
// Created by c.barrera on 21/10/2025.
//

#include <memory>
#include "Player.h"

Player::Player(const std::string &characterName, const int hPMax, const int power, const int armor)
    : Character( characterName,hPMax, power, armor) {
    _playerInventory = std::make_unique<Inventory>();
}

Player::~Player() = default;

void Player::LootItem(const std::shared_ptr<Item> &item) {
    _playerInventory->AddItem(item);
}

void Player::DropItem(const std::shared_ptr<Item> &item) {
    _playerInventory->RemoveItem(item);
}

void Player::DisplayInventory() {
    _playerInventory->Display();
}

int Player::GetInventorySize() {
    return _playerInventory->GetInventorySize();
}
void Player::UseItem(int position) {
    _playerInventory->GetItem(position)->Effect(std::shared_ptr<Player>(this));
    DropItem(_playerInventory->GetItem(position));
}

