struct mathematics 
{
    template <typename scalar_t>
    scalar_t sq(scalar_t x) const 
    {
        return x * x;
    }
};

template <typename scalar_t>
struct more_mathematics 
{
    template <typename other_t>
    static scalar_t product(scalar_t x, other_t y)
    {
        return x * y;
    }
};

int main() {
    double A = mathematics().sq(3.14);
    double B = more_mathematics<double>().product(3.14, 5);

    return 0;
}
