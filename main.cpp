#include "Game.hpp"
#include "array.cpp"

// ngetes dulu gan

int main(){
    Array<Player> *p = new Array<Player>();
    *p+Player(1);
    *p+Player(2);
    AbilityCard a1(1,"a1");
    AbilityCard a2(2,"a2");

    delete p;
    // Array<int> *a = new Array<int>();
    // *a+3;
    // *a+1;
    // cout << "size: " << a->size() << endl;
    // for(int i = 0; i < a->size(); i++){
    //     cout << a->get(i) << endl;
    // }
    // *a-1;
    // cout << "size: " << a->size() << endl;
    // for(int i = 0; i < a->size(); i++){
    //     cout << a->get(i) << endl;
    // }

    // delete a;

    return 0;

}
