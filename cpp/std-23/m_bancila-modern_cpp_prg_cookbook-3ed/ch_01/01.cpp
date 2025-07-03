/// the "how to do it" section
#include <memory>
#include <string>
#include <vector>
#include <cctype>
namespace example_01 {

template <typename F, typename T>
auto apply(F&& f, T value) {
	return f(value);
}

void run() {
	{
		auto i = 42;          // int
		auto d = 42.5;        // double
		auto s = "text";      // char const *
		auto v = { 1, 2, 3 }; // std::initializer_list
	}

	{
		auto b = new char[10] { 0 };           // char*
		auto s1 = std::string{ "text" };       // std::string
		auto v1 = std::vector<int>{ 1, 2, 3 }; // std::vector<int>
		auto p = std::make_shared<int>(42);    // std::shared_ptr<int>
	}

	{
		auto upper = [](char const c) { return toupper(c); };
	}

	{
		auto add = [](auto const a, auto const b) { return a + b; };
	}

	{
		auto add = [](auto const a, auto const b) { return a + b; };
	}
}

} // example_01


// the "how it works" section
#include <map>
#include <string>
#include <vector>
#include <cassert>
namespace example_02 {

auto func1(int const i) -> int { return 2 * i; }

auto func2(int const i) { return 2 * i; }

class foo {
	int x_;
public:
	foo(int const x = 0) : x_{ x } {}
	int& get() { return x_; }
};

auto proxy_get1(foo& f) { return f.get(); }
decltype(auto) proxy_get2(foo& f) { return f.get(); }

struct {
	template <typename T, typename U>
	auto operator () (T const a, U const b) const { return a + b; }
} L;

void run() {
	{
		auto v = std::vector<int>{ 1, 2, 3 };

		// a warning
		//int size1 = v.size();

		auto size2 = v.size();

		// warning or error
		//auto size3 = int{ v.size() };
	}

	{
		std::map<int, std::string> m;

		for (std::map<int, std::string>::const_iterator it = m.cbegin();
			it != m.cend();
			++it)
		{

		}

		for (auto it = m.cbegin(); it != m.cend(); ++it) {

		}
	}

	{
		std::map<int, std::string> m;

		for (std::map<int, std::string>::const_iterator it = m.cbegin();
			it != m.cend();
			++it)
		{

		}

		for (auto it = m.cbegin(); it != m.cend(); ++it) {

		}
	}

	{
		foo f(42);
		auto x = f.get();
		x = 100;
		assert(42 == f.get());

		auto& y = f.get();
		y = 100;
		assert(100 == f.get());
	}

	{
		auto l1 = long long{ 42 };
		using llong = long long;
		auto l2 = llong{ 42 };
		auto l3 = 42LL;

		//auto l4 = (long long){ 42 }; // error
	}

	{
		auto f = foo{ 42 };
		decltype(auto) x = proxy_get2(f);
	}

	{
		using namespace std::string_literals;

		auto ladd = [](auto const a, auto const b) { return a + b; };

		auto i = ladd(40, 2);
		assert(42 == i);

		auto s = ladd("forty"s, "two"s);
		assert("fortytwo"s == s);
	}

	{
		using namespace std::string_literals;

		auto i = L(40, 2);
		assert(42 == i);

		auto s = L("forty"s, "two"s);
		assert("fortytwo"s == s);
	}
}

} // example_02


int main() {
	example_01::run();
	example_02::run();
}
