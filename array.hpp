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
        const T& get(int);
        int size();
        void operator+ (const T&);
        void operator- (const T&);
        bool operator== (const Array&);
};