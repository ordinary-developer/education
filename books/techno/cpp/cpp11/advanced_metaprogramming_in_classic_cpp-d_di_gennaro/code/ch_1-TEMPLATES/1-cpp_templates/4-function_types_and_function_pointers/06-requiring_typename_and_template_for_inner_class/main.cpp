template <typename X>
struct outer 
{
    template <typename T>
    struct innter { };
};

template <typename X>
void do_it()
{
    typename outer<X>::template inner<double> I;
}

int main() {
    return 0;
}
