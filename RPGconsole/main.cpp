#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"


int main() {
    std::string name;
    std::string input;

    std::cout << "- = - = -[ RPG console ]- = - = -" << std::endl;
    //Menu
    /*std::cout << "- - { Main Menu } - -" << std::endl;
    std::cout << "[[1] combat]" << std::endl;
    std::cout << "[[0] quitter]" << std::endl;*/
    //
    //Créa perso
    std::cout << ">>> Creation du personnage du joueur : " << std::endl << "Nom ? ";
    std::cin >> name;
    Player player = Player(name, 100, 2, 1);
    player.Display();
    //
    std::shared_ptr<Enemy> gob;
    *gob= Enemy("gobelin", 10 , 5, 0);
    std::shared_ptr<Enemy> orc;
    *orc = Enemy("Orc", 50 , 10, 0);
    Wave<Enemy> wave = Wave<Enemy>();
    wave.AddEnemy(*gob);
    wave.AddEnemy(*orc);
    wave.DisplayWave();
    while (!wave.IsCompleted()) {
        std::cout << "[[1] attack]" << std::endl;
        std:: cin >> input;
        if (input == "1") {
            wave.GetTarget().TakeDamage(player.GetPower());
            player.TakeDamage(wave.GetWavePower());
            player.Display();
            wave.DisplayWave();
        }
        else {
            std::cout << "commande incorrect" << std::endl;
            std::cout << "[[1] attack]" << std::endl;
            std:: cin >> input;
        }
    }
}
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.