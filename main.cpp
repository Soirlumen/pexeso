#include <iostream>
#include "Pexeso.h"
#include "Player.h"
#include "Gameboard.h"

int main() {
    try {
        // hráči
        Plr p1("kinimod");
        Plr p2("zaba");

        std::vector<Plr> players = {p1, p2};

        // hrací plocha
        Gameboard gb("pic",10); 

        // spuštění hry
        Pexeso hra(players, gb);
        hra.play();
    }
    catch (const std::exception& e) {
        std::cerr << "Chyba: " << e.what() << "\n";
    }

    return 0;
}
