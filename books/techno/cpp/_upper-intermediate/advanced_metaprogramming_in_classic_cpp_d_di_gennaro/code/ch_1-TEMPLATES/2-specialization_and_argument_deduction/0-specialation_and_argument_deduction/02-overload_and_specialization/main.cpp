template <typename scalar_t>
inline scalar_t sq(const scalar_t& x) {  // function template
    return x * x; 
}

inline double sq(const double& x) {     // overload
    return x * x;
}

template <>
inline int sq(const int& x);            // specialization

inline double sq(float x) {             // ok, overloaded sq
    return x * x;                       // may have diff signature
}

//template<>
//inline int sq(const int x);           // error: 
                                        // invalid specialization
                                        // it must have the same
                                        // signature
int main() {
    sq(3.14);
    return 0;
}
