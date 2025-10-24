//
// Created by c.barrera on 22/10/2025.
//

#pragma once
#include <memory>
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

    void WTakeDamage(int damage){
        if(!_enemyList.empty()) {
            for (int i = 0; i < _enemyList.size(); i++) {
                if (!_enemyList[i]->IsDead()) {
                    _enemyList[i]->TakeDamage(damage);
                    return;
                }
            }
        }
    }

    [[nodiscard]] int GetWavePower() {
        int wavePower = 0;
        for(int i = 0; i < _enemyList.size(); i++) {
            if (!_enemyList[i]->IsDead()) wavePower += _enemyList[i]->GetPower();
        }
        return wavePower;
    }

    [[nodiscard]] bool IsCompleted() {
        if (_enemyList.empty())return false;
        for (int i = 0; i < _enemyList.size(); i++) {
            if (!_enemyList[i]->IsDead()) {
                return false;
            }
        }
        return true ;
    }
    std::vector<std::shared_ptr<T>> _enemyList;
};