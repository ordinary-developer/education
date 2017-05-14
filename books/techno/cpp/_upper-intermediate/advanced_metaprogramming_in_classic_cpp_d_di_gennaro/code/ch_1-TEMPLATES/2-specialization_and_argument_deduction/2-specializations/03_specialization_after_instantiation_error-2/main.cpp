template <typename T>
struct C
{
    C(C<void>) { }
};

// here an error will be
template <>
struct C<void> { };

int main() {
    return 0;
}
