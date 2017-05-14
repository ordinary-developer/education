template <typename T = double>
class sum { };

int main() {
    sum<> S1; // ok

    // sum S2; // error

    return 0;
}
