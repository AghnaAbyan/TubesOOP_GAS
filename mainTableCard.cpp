#include <iostream>
#include <fstream>
#include <string>
#include "exception.hpp"
#include "TableCard.cpp"


using namespace std;

/*void readFromFile(const std::string& filename) {
    ifstream file;
    try{
        if (!file.is_open()) {
        throw Exception();
    }
    else{
        string line;
        while (getline(file, line)) {
            cout << line << std::endl;
        }
    }


    }catch(Exception e){
        e.displayMessage();
    }
    
    file.close();
    
}

int main() {
    std::string filename = "test2.txt";
    readFromFile(filename);
    return 0;
}*/

int main(){
    TableCard* a = new TableCard();
    //a->readFileTumpukan("test.txt");
    a->randomTableDeck();
   
}