#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;/*
class Exception{
    public:
        void displayMessage(){
            cout << "Exception :: File Tidak DItemukan" << endl;
        }
};
*/
#include <exception>


class TestException : public exception{
    public:
        const char* what() const throw(){
            return "Hayo";
        }
};


#endif