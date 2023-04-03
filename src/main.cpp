#include "Game/Game.hpp"

// g++ -o bin/main src/main.cpp src/Game/Game.cpp src/Kartu/Kartu.cpp src/Kombo/Kombo.cpp src/InventoryHolder/InventoryHolder.cpp src/Player/Player.cpp src/TableCard/TableCard.cpp src/Commands/Commands.hpp src/Commands/Command.hpp

// ngetes dulu gan

int main(){
    Game *game = new Game();
    game->start();
    delete game;
    return 0;
}
