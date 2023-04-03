// #ifndef COMMAND_HPP
// #define COMMAND_HPP

// #include <vector>
// #include <iostream>
// using namespace std;

// class Game;
// class Player;

// class Commands{ // ABC
//     protected:
//         Game* game;
//         Player* player;
//         vector<Player*> players;

//         bool used;
//         bool disabled;
//     public:
//         Commands(Game& _game): game(&_game), used(false), disabled(false){}
//         ~Commands(){    
//             players.clear();
//         };

//         void use(){
//             used = true;
//         }
//         void disable(){
//             disabled = true;
//         }

//         bool isUsed(){return used;}
//         bool isDisabled(){return disabled;}

//         virtual void action()=0;
// };

// #endif