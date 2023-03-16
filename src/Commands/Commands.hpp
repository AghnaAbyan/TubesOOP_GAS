#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "Game.hpp"
#include "src/Kartu/Kartu.hpp"

using namespace std;

class Commands{ // ABC
    protected:
        Game* game;
        Player* player;
    public:
        ~Commands();
        virtual void action() = 0;
};

class Next: public Commands{
    public:
        Next();
        void action();
};

class Reroll: public Commands{
    public:
        Reroll(Game*, Player*);
        void action();
};

class Multiply: public Commands{
    protected:
        int multiplier;
    public:
        Multiply(Player*, int);
        void action();
};

class Double: public Multiply{
    public:
        Double(Player*);
};

class Quadruple: public Multiply{
    public:
        Quadruple(Player*);
};

class Divide: public Commands{
    protected:
        int divisor;
    public:
        Divide(Player*, int);
        void action();
};

class Half: public Divide{
    public:
        Half(Player*);
};

class Quarter: public Divide{
    public:
        Quarter(Player*);
};

class Reverse: public Commands{
    public:
        Reverse(Game*);
        void action();
};

class Swap: public Commands{
    private:
        AngkaCard* chosenCardA;
        AngkaCard* chosenCardB;
    public:
        Swap();
        void action();
        AngkaCard* chooseCard();
        Player* choosePlayer();
};

class Switch: public Commands{
    public:
        Switch(Player*);
        void action();
        Player* choosePlayer();
};

class Abilityless: public Commands{
    public:
        Abilityless();
        void action();
        Player* choosePlayer();
};

#endif