#include <iostream>
#include <boost/cast.hpp>

using namespace std;
using boost::numeric_cast;
using boost::bad_numeric_cast;

int main() {
    try {
        int i = 32767;
        short s = numeric_cast<short>(i);

        cout << "s = " << s << endl;

        i++;
        s = numeric_cast<short>(i);
    }
    catch (const bad_numeric_cast & e) {
        cerr << e.what() << endl;
    }

    try {
        int i = 300;
        unsigned int ui = numeric_cast<unsigned int>(i);

        cout << ui << endl;

        i *= -1;
        ui = numeric_cast<unsigned int>(i);
    }
    catch(const bad_numeric_cast & e) {
        cerr << e.what() << endl;
    }

    try {
        double d = 3.14;
        int i = numeric_cast<int>(d);

        i = numeric_cast<int>(d);

        cout << i << endl;
    }
    catch (bad_numeric_cast & e) {
        cerr << e.what() << endl;
    }

    try {
        double d = -3.14;
        unsigned int ui = numeric_cast<unsigned int>(d);
        cout << ui << endl;
    }
    catch (bad_numeric_cast & e) {
        cerr << e.what() << endl;
    }
}
