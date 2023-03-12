#include "Game.hpp"

template <class T>
array<T>::array(){
    N = 0;
    data = new T[1];
}

template <class T>
array<T>::~array(){
    delete[] data;
}

template <class T>
void array<T>::addfirst(const T &el){
    data[0] = el;
}

template <class T>
T array<T>::get(int i){
    return data[i];
}

template <class T>
int array<T>::size(){
    return N;
}

template <class T>
void array<T>::operator+ (const T &el){
    if (N == 0){
        addfirst(el);
        N++;
    }
    else{
        T *buff = new T[N+1];
        for(int i = 0; i <= N; i++){
            buff[i] = data[i];
        }
        buff[N] = el;
        delete[] data;
        data = buff;
        N++;
    }
}

template <class T>
void array<T>::operator- (const T &el){
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