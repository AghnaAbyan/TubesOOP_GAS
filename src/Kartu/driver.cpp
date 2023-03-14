#include "Kartu.hpp"
#include "../../array.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main(){
    Array<int> *test = new Array<int>();
    test+1;
    test+2;
    test+3;
    test+4;
    test+5;
    randomizeDeck(*test, 5);
    for(int i =0;i<5; i++){
        cout<< test->get(i) <<" ";

    }
    delete test;
    cout<<endl;
}