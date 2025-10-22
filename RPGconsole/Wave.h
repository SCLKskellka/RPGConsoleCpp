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
    }

    void DisplayWave() {
        for (int i = 0; i < _enemyList.size(); i++) {
            std::cout << "Enemy " << i+1 << " ";
            _enemyList[i]->Display();
        }
    }

    void TakeDamage(int damage){
        for(int i = 0; i < _enemyList.size(); i++) {
            if (!_enemyList[i]->IsDead()) {
                _enemyList[i]->TakeDamage(damage);
                return ;
            }
        }
    }

    [[nodiscard]] int GetWavePower() {
        int wavePower = 0;
        for(int i = 0; i < _enemyList.size(); i++) {
            wavePower += _enemyList[i]->GetPower();
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