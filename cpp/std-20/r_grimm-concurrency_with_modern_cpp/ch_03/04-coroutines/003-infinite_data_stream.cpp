#include <coroutine>
#include <memory>
#include <iostream>


template <typename T>
struct Generator {

	struct promise_type;
	using handle_type = std::coroutine_handle<promise_type>;

	handle_type coro_;

	Generator(handle_type h) : coro_(h) {}

	~Generator() {
		if (coro_) {
			coro_.destroy();
		}
	}

	Generator(const Generator&) = delete;
	Generator& operator = (const Generator&) = delete;
	Generator(Generator&& other) noexcept : coro_(other.coro_)
	{
		other.coro_ = nullptr;
	}
	Generator& operator = (Generator&& other) noexcept {
		coro_ = other.coro_;
		other.coro_ = nullptr;
		return *this;
	}

	T getValue() {
		return coro_.promise().current_value_;
	}

	bool next() {
		coro_.resume();
		return not coro_.done();
	}


	struct promise_type {
		promise_type() = default;

		~promise_type() = default;

		auto initial_suspend() { return std::suspend_always(); }

		auto final_suspend() noexcept { return std::suspend_always{}; }

		auto get_return_object() {
			return Generator{ handle_type::from_promise(*this) };
		}

		auto return_void() { return std::suspend_never{}; }

		auto yield_value(const T value) {
			current_value_ = value;
			return std::suspend_always();
		}

		void unhandled_exception() { std::exit(1); }

		T current_value_;
	};

};

Generator<int> getNext(int start = 0, int step = 1) {
	auto value = start;
	while (true) {
		co_yield value;
		value += step;
	}
}


int main() {
	std::cout << '\n';

	std::cout << "getNext(): ";
	auto gen = getNext();
	for (int i = 0; i <= 10; ++i) {
		gen.next();
		std::cout << " " << gen.getValue();
	}

	std::cout << "\n\n";

	std::cout << "getNext(100, -10): ";
	auto gen2 = getNext(100, -10);
	for (int i = 0; i <= 20; ++i) {
		gen2.next();
		std::cout << " " << gen2.getValue();
	}

	std::cout << '\n';
}
