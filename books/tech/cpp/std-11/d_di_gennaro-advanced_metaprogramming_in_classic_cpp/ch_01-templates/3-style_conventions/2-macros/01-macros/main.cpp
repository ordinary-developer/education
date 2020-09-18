#ifndef MXT_filename_
#define MXT_filename_           // this is "exported" - let's name it MXT_*
#endif // MXT_filename_

#define mXT_MYVALUE 3           // this macro has limited "scope"
const int VALUE = mXT_MYVALUE;  // let's name it mXT_*
#undef mXT_MYVALUE              

#ifdef _WIN32
#define mxt_native_dbl_isfinite     _finite
#else
#define mxt_native_dbl_isfinite     isfinite
#endif

#define mXT_PROCESS 
#ifdef mXT_PROCESS
#define  MXT_VALUE 1
#endif
#undef mXT_PROCESS

#define MXT_NAMESPACE_BEGIN(x)      namespace x {
#define MXT_NAMESPACE_END(x)        }
#define MXT_NAMESPACE_NULL_BEGIN()  namespace {
#define MXT_NAMESPACE_NULL_END()    }

///////////////////////////////////////////////
MXT_NAMESPACE_BEGIN(XT)
///////////////////////////////////////////////

///////////////////////////////////////////////
MXT_NAMESPACE_END(XT)
///////////////////////////////////////////////


#define MXT_M_MAX(a, b)     ((a) < (b) ? (b) : (a))
#define MXT_M_MIN(a, b)     ((a) < (b) ? (a) : (b))
#define MXT_M_ABS(a)        ((a) < 0 ? -(a) : (a))
#define MXT_M_SQ(a)         ((a) * (a))

template <int N>
struct SomeClass {
    static const int value = MXT_M_SQ(N) / MXT_M_MAX(N, 1);
};


#include <iostream>
int main() {
    int i = MXT_VALUE;
    std::cout << i << std::endl;

    return 0;
}
