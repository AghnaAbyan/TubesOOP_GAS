#include "Game.hpp"

// g++ -o m main.cpp Game.cpp src/Kartu/Kartu.cpp src/Kombo/Kombo.cpp InventoryHolder.cpp Player.cpp TableCard.cpp

// ngetes dulu gan

int main(){
    Game *game = new Game();
    game->start();
    delete game;
    return 0;

}
