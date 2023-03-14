#ifndef ARRAY_HPP
#define ARRAY_HPP

// Kelas generik array
template <class T>
class Array{
    private:
        int N;
        T *data;
    public:
        Array();
        ~Array();

        void addfirst(const T&);
        T get(int);
        int size();
        void set(int, T);
        void operator+ (const T&);
        void operator- (const T&);
        bool operator== (const Array&);
        T operator-- ();
};

#endif