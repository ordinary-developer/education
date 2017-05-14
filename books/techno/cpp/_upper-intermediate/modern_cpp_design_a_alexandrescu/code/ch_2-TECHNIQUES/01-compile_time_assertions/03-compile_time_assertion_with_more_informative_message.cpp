template<bool> struct CompileTimeError;
template<> struct CompileTimeError<true> { };

#define STATIC_CHECK(expr) \
    (CompileTimeError<0 != (expr)>())

template <class To, class From>
To safe_reinterpret_cast(From from)
{
    STATIC_CHECK(sizeof(From) <= sizeof(To));
    return To();
}


int main() {
    int a = 5;
    char b = safe_reinterpret_cast<char>(a);

    return 0;
}
