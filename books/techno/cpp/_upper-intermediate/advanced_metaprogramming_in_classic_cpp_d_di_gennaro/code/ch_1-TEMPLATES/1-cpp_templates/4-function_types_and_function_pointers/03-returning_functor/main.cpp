template <typename T>
struct X 
{
    T member_;

    X(T value) : member_(value) { }
};

template <typename T>
X<T> identify_by_val(T x) 
{
    return X<T>(x);
}

template <typename T>
X<T> identify_by_ref(const T& x)
{
    return X<T>(x);
}

double f(int) { return 3.1415; }

int main() {
    // ok: function decays to pointer-to-function:
    // template instantiated with T = double (*)(int)
    identify_by_val(f); 

    // error: no decay
    // template instantiated with T = double(int)
    //identify_by_ref(f);

    return 0;
}
