class mathematics1 {
    template <typename scalar_t>
    inline scalar_t sq(const scalar_t& x) {
        return x;
    }

    // illegal specialization
    /*
    template <>
    inline int sq(const int& x) { 
        return x;
    }*/
};


template <typename scalar_t>
inline scalar_t gsq(const scalar_t& x) {
    return x;
}

template <>
inline int gsq(const int& x) { 
    return x;
}

class mathematics {
    template <typename scalar_t>
    inline scalar_t sq(const scalar_t& x) {
        return gsq(x);
    }
};


int main() {
    return 0;
}
