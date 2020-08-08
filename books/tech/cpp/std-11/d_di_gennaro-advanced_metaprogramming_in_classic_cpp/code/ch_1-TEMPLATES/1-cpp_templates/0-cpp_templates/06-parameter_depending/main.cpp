template
<
    typename T,
    int (*FUNC)(T)
>
class X { };

template
<
    typename T,
    T VALUE
>
class Y { };

int main() {
    Y<int, 7> y1;

    // will not be compiled
    // Y<double, 3> y2;

    return 0;
}
