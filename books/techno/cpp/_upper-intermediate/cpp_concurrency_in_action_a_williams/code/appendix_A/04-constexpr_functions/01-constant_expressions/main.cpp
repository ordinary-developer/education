int bounds = 99;
const int bounds2 = 99;
const int forty_two = 42;

// specify the bounds of an array
// int array[bounds]; // error
int array2[bounds2]; // OK

// specify the value of a nontype template parameter
template <unsigned size>
struct test { };
// test<bounds> ia{}; // error
test<bounds2> ia2{}; // OK

// provide an  initializer for a static const class data member
// of integral type in the class definition
class X {
    static const int the_answer = forty_two;
};

// provide an initializer for a built-in type or aggregate 
// that can be used for static initialization
struct my_aggregate {
    int a, b;
};
static my_aggregate ma1 = { forty_two, 123 }; // static initialization
int dummy = 257;
static my_aggregate ma2 = { dummy, dummy }; // dynamic initialization


int main() {
    
    return 0;
}
