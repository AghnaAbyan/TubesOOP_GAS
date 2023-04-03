#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class Utils{
    public:
        static mt19937 rng(){
            random_device rd;
            return mt19937(rd());
        }

        template<class T>
        static void shuffle(vector<T> &v){
            std::shuffle(v.begin(), v.end(), Utils::rng());
        }
};