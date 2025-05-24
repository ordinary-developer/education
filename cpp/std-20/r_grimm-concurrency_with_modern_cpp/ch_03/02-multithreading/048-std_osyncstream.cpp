#include <syncstream>
#include <iostream>
int main() {
	std::osyncstream bout1(std::cout);
	bout1 << "Hello, ";
	{
		std::osyncstream(bout1.get_wrapped()) << "Goodbye, " << "Planet!" << '\n';
	}
	bout1 << "World!" << '\n';
}
