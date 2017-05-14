#define STATIC_CHECK(expr) { char unamed[(expr) ? 1 : 0]; }

template <class To, class From>
To safe_reinterpret_cast(From from)
{
    STATIC_CHECK(sizeof(From) <= sizeof(To));
    return reinterpret_cast<To>(from);
}

int main() {
    int intValue = 5;
    char c = safe_reinterpret_cast<char>(intValue);

    return 0;
}
