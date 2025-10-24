cmake_minimum_required(VERSION 4.0)
project(RPGconsole)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPGconsole main.cpp
        Character.cpp
        Character.h
        Player.cpp
        Player.h
        Enemy.cpp
        Enemy.h
        Wave.h
        Game.cpp
        Game.h
        Item.cpp
        Item.h
        Inventory.cpp
        Inventory.h
        Potion.cpp
        Potion.h
)
