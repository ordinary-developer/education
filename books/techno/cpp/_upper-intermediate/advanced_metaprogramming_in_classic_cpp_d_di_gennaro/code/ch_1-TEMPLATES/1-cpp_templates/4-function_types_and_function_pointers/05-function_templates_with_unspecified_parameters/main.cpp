typedef double (*FUNC_T)(double);

template <typename X>
struct outer
{
    template <typename T>
    static T g(T x)
    {
        return x + 1;
    }
};

template <typename X>
void do_it()
{
    // FUNC_T f1 = outer<X>::g<double>; // error
    FUNC_T f2 = outer<X>::template g<double>; // ok
}

int main() {
    return 0;   
}
