#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
T sciToNum(const string & str) {
	stringstream ss(str);
	T tmp;
	ss >> tmp;

	if (ss.fail()) {
		string s = "Unable to format ";
		s += str;
		s += " as a number!";
		throw (s);
	}

	return (tmp);
}


int main() {
	try {
		cout << sciToNum<double>("7.0") << endl;
		cout << sciToNum<float>("7.0") << endl;
		cout << sciToNum<int>("7.0") << endl;
	}
	catch (const string & e) {
		cerr << "Whoops: " << e << endl;
	}
}
