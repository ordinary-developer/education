template <typename T>
struct X 
{
    T member_;

    X(T value) : member_(value) { }
};

double f(int) { return 3.1415; }

int main() {
    // X<double (int)> t1(f); // error: connot construct 'member_'
    X<double (*)(int)> t2(f); // ok

    return 0;
}
