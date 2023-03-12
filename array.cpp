#include "Game.hpp"

template <class T>
Array<T>::Array(){
    N = 0;
    data = new T[1];
}

template <class T>
Array<T>::~Array(){
    delete[] data;
}

template <class T>
void Array<T>::addfirst(const T &el){
    data[0] = el;
}

template <class T>
T Array<T>::get(int i){
    return data[i];
}

template <class T>
int Array<T>::size(){
    return N;
}

template <class T>
void Array<T>::operator+ (const T &el){
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
void Array<T>::operator- (const T &el){
    bool found = false;
    int i = 0;
    while(!found && i < N){
        if(data[i] == el){
            if (i == N-1){
                N--;
            }
            else{
                for(int j = i; j < N; j++){
                    data[j] = data[j+1];
                }
                N--;
            }
            found = true;
        }
        i++;
    }
}

template <class T>
bool Array<T>::operator== (const Array &arr){
    if (N != arr.N){
        return false;
    }
    else{
        bool same = true;
        int i = 0;
        while(i < N && same){
            if(data[i] != arr.data[i]){
                same = false;
            }
            i++;
        }
        return same;
    }
    
}