#include "Game.hpp"

template <class T>
array<T>::array(int n){
    N = n;
    data = new T[n];
}

template <class T>
array<T>::~array(){

}

template <class T>
int array<T>::size(){
    return N;
}

template <class T>
void array<T>::operator+ (T el){
    buff = new T[N+1];
    for(int i = 0; i < N; i++){
        buff[i] = data[i];
    }
    buff[N] = el;
    delete data;
    data = buff;
    N++;
}

template <class T>
void array<T>::operator- (T &el){
    bool found = false;
    int i = 0;
    while(!found && i < N){
        if (i == N-1){
            delete data[i];
            N--;
        }
        else{
            for(int j = i; j < N; j++){
                data[j] = data[j+1];
            }
            delete data[N-1];
            N--;
        }
    }
}