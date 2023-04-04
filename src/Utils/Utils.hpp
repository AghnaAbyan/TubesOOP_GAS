#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Utils{
    public:
        static void rng_seed(){
            srand((unsigned int)time(NULL));
        }

        template<class T>
        static void shuffle(vector<T> &v){
            rng_seed();
            random_shuffle(v.begin(), v.end());
        }
        static string toupper(string s){
            for(char& c : s){
                c = std::toupper(c);
            }
            return s;
        }
};