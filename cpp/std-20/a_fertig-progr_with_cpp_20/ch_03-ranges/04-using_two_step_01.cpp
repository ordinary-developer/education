#include <iostream>

#ifdef WILL_NOT_COMPILE
struct Container {};     // Container without begin
int* begin(Container);   // Free-function begin for Container
                            
struct OtherContainer {  // Container with begin
	int* begin();
};

void Use(auto& c) {
	begin(c);       // Call ::begin(Container)
	std::begin(c);  // Call STL std::begin
}

int* begin(Container)  // Free-function begin for Container
{
	std::cout << "begin(Container)\n";
	return nullptr;
}

int* OtherContainer::begin() {
	std::cout << "OtherContainer::begin()\n";
	return nullptr;
}
#endif

int main() {
#ifdef WILL_NOT_COMPILE
	Container c{};
	
	Use(c);

#endif
}
