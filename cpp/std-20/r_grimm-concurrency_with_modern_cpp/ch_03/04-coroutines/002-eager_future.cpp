#include <coroutine>
#include <iostream>
#include <memory>


template <typename T>
struct MyFuture {
	std::shared_ptr<T> value_;

	MyFuture(std::shared_ptr<T> p) : value_(p) {}

	~MyFuture() {}

	T get() { return *value_; }

	struct promise_type {
		std::shared_ptr<T> ptr_ = std::make_shared<T>();

		~promise_type() {}

		MyFuture<T> get_return_object() { return ptr_; }

		void return_value(T v) { *ptr_ = v; }

		std::suspend_never initial_suspend() { return {}; }

		std::suspend_never final_suspend() noexcept { return {}; }

		void unhandled_exception() { std::exit(1); }
	};
};

MyFuture<int> createFuture() { co_return 2021; }


int main() {
	std::cout << '\n';

	auto fut = createFuture();
	std::cout << "fut.get(): " << fut.get() << '\n';

	std::cout << '\n';
}
