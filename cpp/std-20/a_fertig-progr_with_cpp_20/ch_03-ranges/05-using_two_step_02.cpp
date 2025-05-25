#include <iostream>

struct Container {};    // Container without begin
int* begin(Container)   // Free-function begin for Container
{
	std::cout << "begin(Container)\n";
	return nullptr;
}

struct OtherContainer { // Container with begin
	int* begin() {
		std::cout << "OtherContainer::begin()\n";
		return nullptr;
	}
};

void Use(auto& c) {
	using std::begin; // Bring std::begin in the namespace
	begin(c);
}

int main() {
	Container c{};
	Use(c);

	OtherContainer oc{};
	Use(oc);
}
