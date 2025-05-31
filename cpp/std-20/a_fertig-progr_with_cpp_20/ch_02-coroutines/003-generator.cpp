#include <new>
#include <coroutine>
#include <cstdio>
#include <exception>
#include <utility>
#include <iostream>


template <typename T, typename G>
struct promise_type_base {
	T mValue;                                    // The value yielded or returned from a coroutine

	auto yield_value(T value)                    // Invoked by co_yeild or co_return
	{
		mValue = std::move(value);               // Store the yielded value for access outise the coroutine
		return std::suspend_always{};            // Suspend the coroutine here
	}
	
	G get_return_object() { return G{ this }; }; // Return genreator

	std::suspend_always initial_suspend() { return {}; }
	std::suspend_always final_suspend() noexcept { return {}; }
	void return_void() {}
	void unhandled_exception() { std::terminate(); }

	static auto get_return_object_on_allocation_failure() { return G{ nullptr }; }
};

namespace coro_iterator {
	template <typename PT>
	struct iterator {
		std::coroutine_handle<PT> mCoroHdl{ nullptr };

		void resume()
		{
			if (not mCoroHdl.done()) {
				mCoroHdl.resume();
			}
		}

		iterator() = default;
		iterator(std::coroutine_handle<PT> hco) : mCoroHdl{ hco }
		{
			resume();
		}

		void operator++() { resume(); }
		bool operator==(const iterator&) const { return mCoroHdl.done(); }

		const auto& operator*() const { return mCoroHdl.promise().mValue; }
	};

} // namespace coro_iterator

template <typename T>
struct generator {
	using promise_type =
		promise_type_base<T, generator>;                               // The PromiseType
	using PromiseTypeHandle = std::coroutine_handle<promise_type>;

	// Make the generator iterable
	using iterator = coro_iterator::iterator<promise_type>;
	iterator begin() { return { mCoroHdl }; }
	iterator end() { return {}; }

	generator(generator const&) = delete;
	generator(generator&& rhs) : mCoroHdl(std::exchange(rhs.mCoroHdl, nullptr)) {}

	~generator()
	{
		// We have to maintain the life-time of the coroutine
		if (mCoroHdl) {
			mCoroHdl.destroy();
		}
	}

private:
	friend promise_type;                                               // As the default ctor is private promise_type needs to be a friend

	explicit generator(promise_type* p) : mCoroHdl{ PromiseTypeHandle::from_promise(*p) } {}

	PromiseTypeHandle mCoroHdl;
};

using IntGenerator = generator<int>;

void UseCounterValue(int i);

IntGenerator                                                           // Returning a coroutine object
counter(int start, int end)
{
	while (start <= end) {
		co_yield start;                                                // Yielding a value and giving control back to the caller
		++start;
	}
}

void UseCounter()
{
	auto g = counter(1, 5);

	// This sequence rusn from 1 to 5
	for (auto i : g) {
		UseCounterValue(i);
	}
}

void UseCounterValue(int i)
{
	printf("%d\n", i);
}


int main() {
	UseCounter();
}
