#include "Game.hpp"
#include "array.cpp"

// ngetes dulu gan

int main(){
    array<int> *a = new array<int>();
    *a+3;
    *a+1;
    cout << "size: " << a->size() << endl;
    cout << a->get(0) << endl;
    cout << a->get(1) << endl;

    delete a;

    return 0;
}
