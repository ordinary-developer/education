template <typename scalar_t>
scalar_t sq(const scalar_t& x) 
{
    return x;
}

template 
<
    typename scalar_t,
    bool EXTRA_PRECISION = false,
    typename promotion_t = scalar_t
>
class sum { };

int main() {
    sq(3.14); // sq<double>

    sum<double> S1;       // EXTRA_PRECISION = false
    sum<double, true> S2; // EXTRA_PRECISION = true

    return 0;
}
