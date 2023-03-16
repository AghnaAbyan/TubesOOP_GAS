#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "Game.hpp"
#include "src/Kartu/Kartu.hpp"
#include <algorithm>

using namespace std;

class Commands{ // ABC
    protected:
        Game& game;
        Player* player;
        vector<Player*> players;

        bool used;
        bool disabled;
    public:
        Commands(Game& _game): game(_game), player(_game.getCurrentPlayer()), players(game.getPlayers()), used(false), disabled(false){}
        ~Commands();
        Player* chooseOtherPlayer();
        void use();
        void disable();

        bool isUsed(){return used;}
        bool isDisabled(){return disabled;}

        virtual void action() = 0;
};

class Next: public Commands{
    public:
        Next(Game& _game): Commands(_game){}
        void action();
};

class Reroll: public Commands{
    public:
        Reroll(Game& _game): Commands(_game){}
        void action();
};

class Multiply: public Commands{
    protected:
        int multiplier;
    public:
        Multiply(Game& _game, int _multiplier): Commands(_game), multiplier(_multiplier){}
        void action();
};

class Double: public Multiply{
    public:
        Double(Game& _game): Multiply(_game, 2){}
};

class Quadruple: public Multiply{
    public:
        Quadruple(Game& _game): Multiply(_game, 4){}
};

class Divide: public Commands{
    protected:
        int divisor;
    public:
        Divide(Game& _game, int _divisor): Commands(_game), divisor(_divisor){}
        void action();
};

class Half: public Divide{
    public:
        Half(Game& _game): Divide(_game, 2){}
};

class Quarter: public Divide{
    public:
        Quarter(Game& _game): Divide(_game, 4){}
};

class Reverse: public Commands{
    public:
        Reverse(Game& _game): Commands(_game){}
        void action();
};

class Swap: public Commands{
    public:
        Swap(Game& _game): Commands(_game){}
        void action();
        AngkaCard& chooseCard(Player*);
};

class Switch: public Commands{
    public:
        Switch(Game& _game): Commands(_game){}
        void action();
};

class Abilityless: public Commands{
    public:
        Abilityless(Game& _game): Commands(_game){}
        void action();
};

#endif