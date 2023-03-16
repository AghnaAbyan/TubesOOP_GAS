#include "../../Game.hpp"
//Compile code: g++ -o m driver.cpp ../../Game.cpp ../Kartu/Kartu.cpp Kombo.cpp ../../InventoryHolder.cpp ../../Player.cpp ../../TableCard.cpp


int main(){
    Game *game = new Game();
    game->testCom();
    delete game;
    return 0;
    
}