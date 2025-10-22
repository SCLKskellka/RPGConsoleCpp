//
// Created by c.barrera on 22/10/2025.
//

#pragma once
#include <vector>

#include "Enemy.h"

template<typename T>

class Wave {
public:
    Wave() = default;
    ~Wave() = default;
    void AddEnemy(Enemy enemy) {
        _enemyList.push_back(std::make_unique<Enemy>(enemy));
        std::cout << "add" << std::endl;
    }

    void DisplayWave() {
        for (int i = 0; i < _enemyList.size(); i++) {
            std::cout << "Enemy n°" << i+1 << " ";
            const std::unique_ptr<Enemy> tempo = _enemyList[i];
            tempo->Display();
        }
    }

    Enemy GetTarget(){
        for(int i = 0; i < _enemyList.size(); i++) {
            if (!_enemyList[i].get()->IsDead()) {
                return *_enemyList[i];
            }
        }
        return *_enemyList[_enemyList.size() - 1];
    }

    [[nodiscard]] int GetWavePower() {
        int wavePower = 0;
        for(int i = 0; i < _enemyList.size(); i++) {
            wavePower += _enemyList[i].get()->GetPower();
        }
        return wavePower;
    }

    [[nodiscard]] bool IsCompleted() {
        for(int i = 0; i < _enemyList.size(); i++) {
            if (!_enemyList[i].get()->IsDead()) {
                return false;
            }
        }
        return true;
    }
    std::vector<std::unique_ptr<T>> _enemyList;
};