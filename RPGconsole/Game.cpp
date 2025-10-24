//
// Created by c.barrera on 23/10/2025.
//
#include <memory>
#include "Game.h"
#include "Character.h"
#include "Wave.h"
#include "Player.h"
#include "Enemy.h"
#include "Potion.h"


void Game::Menu() {
    std::string input;

    std::cout << "- = - = -[ RPG console ]- = - = -" << std::endl;
    //Menu
    std::cout << "- - { Menu principale } - -" << std::endl;
    std::cout << "[1] Aventure" << std::endl;
    std::cout << "[0] Quitter" << std::endl;
    //

    std::cin >> input;
    if(input == "1") {
        NewPlayerCharacter();
    }
    else if(input == "0") {
        std::cout << "MERCI !" << std::endl;
    }
    else {
        std::cout << "Commande incorrect" << std::endl;
        Menu();
    }
}

void Game::NewPlayerCharacter() {
    std::string name;

    std::cout << ">>> Creation du personnage du joueur : " << std::endl << "Nom ? ";
    std::cin >> name;
    Player player = Player (name, 100, 10, 5) ;
    player.Display();
    Adventure(player);
}

Wave<Enemy> Game::FirstWaveCreator() {
    std::unique_ptr<Enemy> gob1 = std::make_unique<Enemy>("gobelin", 10 , 5, 0);
    std::unique_ptr<Enemy> orc1= std::make_unique<Enemy>("Orc", 50 , 10, 0);
    std::vector<Enemy> enemies = std::vector<Enemy>();
    enemies.push_back(*gob1);
    enemies.push_back(*orc1);
    Wave<Enemy> wave1 = Wave<Enemy>();
    wave1.AddEnemy(*gob1);
    wave1.AddEnemy(*orc1);
    return wave1;
}

Wave<Enemy> Game::SecondWaveCreator() {
    std::shared_ptr<Enemy> orc2 = std::make_shared<Enemy>("Guerrier orc", 10 , 5, 0);
    std::shared_ptr<Enemy> orc3= std::make_shared<Enemy>("Guerrier orc", 50 , 10, 0);
    std::shared_ptr<Enemy> chiefOrc= std::make_shared<Enemy>("Chef orc", 50 , 10, 0);
    std::vector<Enemy> enemies = std::vector<Enemy>();
    enemies.push_back(*orc2);
    enemies.push_back(*orc3);
    enemies.push_back(*chiefOrc);
    Wave<Enemy> wave2 = Wave<Enemy>();
    wave2.AddEnemy(*orc2);
    wave2.AddEnemy(*orc3);
    wave2.AddEnemy(*chiefOrc);
    return wave2;
}

void Game::Adventure(Player &player) {
    std::string input;

    std::cout << "- - { Choisissez un lieu } - -" << std::endl;
    std::cout << "[1] Foret" << std::endl;
    std::cout << "[2] Montagnes" << std::endl;
    std::cout << "[0] Retour" << std::endl;

    std::cin >> input;

    if(input == "1") {
        Battle(1, player);
    }
    else if(input == "2") {
        Battle(2, player);
    }
    else if(input == "0") {
        Menu();
    }
    else {
        std::cout << "Commande incorrect" << std::endl;
        Adventure(player);
    }
}

void Game::Battle(const int id, Player &player) {
    int input;
    Wave<Enemy> wave;

    std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
    if (id == 1) {
        wave = FirstWaveCreator();
        player->Display();
        wave.DisplayWave();
        std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
    }
    else if(id == 2) {
        wave = SecondWaveCreator();
        player->Display();
        wave.DisplayWave();
        std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
    }
     else{
         std::cout << "Commande incorrect" << std::endl;
    }
    while ( !wave.IsCompleted()) {
        if (player->IsDead())break;
        std::cout << "[1] attack" << std::endl;
        std::cout << "[2] passer" << std::endl;
        std::cout << "[3] fuir" << std::endl;
        std::cout << "[4] utiliser un objet" << std::endl;
        std:: cin >> input;
        if (input == 1) {
            std::shared_ptr<Player> playerpt = std::make_shared<Player>();
            wave.WTakeDamage(player->GetPower(),player);
            player.TakeDamage(wave.GetWavePower());
            player.Display();
            std::cout << std::endl;
            wave.DisplayWave();
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
        }
        else if(input == 2) {
            player.TakeDamage(wave.GetWavePower());
            player.Display();
            wave.DisplayWave();
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
        }
        else if(input == 3) {
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
            std::cout << "Vous prenez la fuite"<< std::endl;
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-" << std::endl << std::endl;
            Adventure(player);
        }
        else if(input == 4) {
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
            player.DisplayInventory();
            std::cout << "Selectionnez votre objet"<< std::endl;
            std::cout << "[999] retour au choix precedent"<< std::endl;
            std::cin >> input;
            std::cout << "-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-"<< std::endl;
            if(input < player.GetInventorySize() ) {
                player.UseItem(input);
            }
            else if(input == 999 ) {
                Battle(id, player);
            }
            else {
                std::cout << "commande incorrect" << std::endl;
                std::cout << "[1] attack" << std::endl;
                std:: cin >> input;
            }
        }
        else {
            std::cout << "commande incorrect" << std::endl;
            std::cout << "[1] attack" << std::endl;
            std:: cin >> input;
        }
    }
    if(player.IsDead()) {
        std::cout << "{{ Vous etes mort}}" << std::endl;
        Menu();
    }
    if (wave.IsCompleted()) {
        std::cout << "{{ Vous avez vaincu vos assaillants}}" << std::endl;
        const std::shared_ptr<Potion> potion = std::make_shared<Potion>("Potion",25);
        player.LootItem(potion);
        std::cout << "= Vous obtenez une potion ! =" << std::endl;
        Adventure(player);
    }
}
