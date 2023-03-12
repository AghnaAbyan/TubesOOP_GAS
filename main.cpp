#include "Game.hpp"
#include "array.cpp"

// ngetes dulu gan

int main(){
    Array<int> *a = new Array<int>();
    *a+3;
    *a+1;
    cout << "size: " << a->size() << endl;
    for(int i = 0; i < a->size(); i++){
        cout << a->get(i) << endl;
    }
    *a-1;
    cout << "size: " << a->size() << endl;
    for(int i = 0; i < a->size(); i++){
        cout << a->get(i) << endl;
    }

    delete a;

    return 0;

    /* Kira" main nya
    InventoryHolder *inv = new InventoryHolder();
    
    while(InventoryHolder::game <= 6){
        inv->newGame();
        while(InventoryHolder::round <= 5){
            inv->newround();

        }
    }
    
    
    
    */
}
