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

void Player::Display() {
    std::cout << std::endl<< std::endl;
    std::cout << "{| "<< _characterName << "  [Lvl-" << _lvl << "] |}" << std::endl;
    std::cout << ">> HP: "<< _characterHP << "/" << _characterHPMax << std::endl;
    std::cout << ">> XP: "<< _xp << "/" << _maxXP << std::endl;
    std::cout << "<Power> "<< _power << std::endl;
    std::cout << "<Armor> "<< _armor << std::endl;
    std::cout << std::endl<< std::endl;
}

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
void Player::UseItem(int position, Player &player) {
    _playerInventory->GetItem(position)->Effect( player);
    DropItem(_playerInventory->GetItem(position));
}

