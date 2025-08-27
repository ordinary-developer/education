#include <iostream>
#include <cmath>

using namespace std;

bool doubleEquals(double left, double right, double epsilon) {
	return (fabs(left - right) < epsilon);
}

bool doubleLess(double left, double right, double epsilon, bool orequal = false) {
	if (fabs(left - right) < epsilon) {
		return (orequal);
	}

	return (left < right);
}

bool doubleGreater(double left, double right, double epsilon, bool orequal = false) {
	if (fabs(left - right) < epsilon) {
		return (orequal);
	}
	return (left > right);
}

int main() {
	double first = 0.33333333;
	double second = 1.0 / 3.0;
	cout << first << endl;
	cout << second << endl;

	cout << boolalpha << (first == second) << endl;
	cout << doubleEquals(first, second, .0001) << endl;
	cout << doubleLess(first, second, .0001) << endl;
	cout << doubleGreater(first, second, .0001) << endl;
	cout << doubleLess(first, second, .0001, true) << endl;
	cout << doubleGreater(first, second, 0.0001, true) << endl;
}
