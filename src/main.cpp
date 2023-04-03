#include "Game/Game.hpp"

// g++ src/main.cpp src/Game/Game.cpp src/Kartu/Kartu.cpp src/Kombo/Kombo.cpp src/InventoryHolder/InventoryHolder.cpp src/Player/Player.cpp src/TableCard/TableCard.cpp -o bin/main

// ngetes dulu gan

int main(){
    cout<<"starting"<<endl;
    Game *game = new Game();
    game->start();
    cout<<"end game"<<endl;
    delete game;
    return 0;
}
