template <typename T>
class something {
    public:
        something() // ok: don't write something<T>
        {
            // at local level, 'something' alone is illegal
        }

        something(const something& that) // ok: 'something&' 
        { }                              // statnds for 'something<T>&'

        template <typename other_t>
        something(const something<other_t>& that) { }
};


int main() { 
    return 0;
}
