#include "Kartu.cpp"
#include <iostream>
#include <vector>
using namespace std;
int main(){
    std::vector<int> test{1, 2, 3, 4, 5};
    randomizeDeck(test, 5);
    for(int i =0;i<5; i++){
        cout<< test[i]<<" ";

    }
    cout<<endl;
}