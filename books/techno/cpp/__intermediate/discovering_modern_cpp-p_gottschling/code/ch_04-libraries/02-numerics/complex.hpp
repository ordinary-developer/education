#include <cmath>
#include <iostream>

class complex
{
  public:
    complex(double r, double i) : r{r}, i{i} {}
    complex(double r) : r{r} {}
    complex() {}

    complex& operator= (const complex& c) 
    {
        r= c.r; i= c.i;
        return *this;
    }

    complex& operator= (double rn) 
    {
        r= rn; i= 0.0;
        return *this;
    }

    friend inline double const& real(const complex& c) { return c.r; } 
    friend inline double& real(complex& c) { return c.r; } 

    friend inline double const& imag(const complex& c) { return c.i; } 
    friend inline double& imag(complex& c) { return c.i; }  

    friend inline double abs(const complex& c) { 
        return sqrt(pow(imag(c), 2) + pow(real(c), 2));
    }

    friend complex operator+(const complex& c1, const complex& c2) {
        return complex(real(c1) + real(c2), imag(c1) + imag(c2));
    }

    friend complex operator+(double d, const complex& c2) {
        return complex(d + real(c2), imag(c2));
    }

    friend complex operator-(const complex& c1, const complex& c2) {
        return {c1.r - c2.r, c1.i - c2.i};
    }

    friend complex operator*(const complex& c1, const complex& c2)
    {
        return complex(real(c1) * real(c2) - imag(c1) * imag(c2),
                       real(c1) * imag(c2) + imag(c1) * real(c2));
    }

    friend std::ostream& operator<<(std::ostream& os, complex c) {
        os << '(' << real(c) << ',' << imag(c) << ")";
        return os;
    }

  private:
    double r= 0.0, i= 0.0;
};

