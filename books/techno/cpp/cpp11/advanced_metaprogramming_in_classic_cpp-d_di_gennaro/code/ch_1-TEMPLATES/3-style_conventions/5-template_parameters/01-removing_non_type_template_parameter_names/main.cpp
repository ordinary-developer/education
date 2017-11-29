// here an error may be
// since some compilers define BIGENDIAND as a macro
template <typename T, bool BIGENDIAN = false>
class SomeClass { };

template <typename T>
class SomeClass<T, true> { };

// a safe declaration would be
template <typename T, bool = false>
class SomeClass2 { };


int main() {
    return 0;
}
