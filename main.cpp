#include <iostream>
#include "Pexeso.h"
#include "Player.h"
#include "Gameboard.h"

int main() {
    try {
        // vytvoření hráčů
        Player p1("Alice");
        Player p2("Bob");

        std::vector<Player> players = {p1, p2};

        // vytvoření hrací plochy s kartami
        Gameboard gb("pic",4); // třeba 4 páry = 8 karet

        // spuštění hry
        Pexeso hra(players, gb);
        hra.play();
    }
    catch (const std::exception& e) {
        std::cerr << "Chyba: " << e.what() << "\n";
    }

    return 0;
}
