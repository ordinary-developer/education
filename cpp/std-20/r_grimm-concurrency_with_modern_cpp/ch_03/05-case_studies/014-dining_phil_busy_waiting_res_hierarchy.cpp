#include <atomic>
#include <chrono>
#include <format>
#include <iostream>
#include <mutex>
#include <thread>


std::mutex gMut;
void syncOutput(const std::string& str) {
	std::lock_guard<std::mutex> _(gMut);
	std::cout << str;
}

int myrand(int min, int max) {
	return rand() % (max - min) + min;
}

void lock(std::atomic_flag& m) {
	while (m.test_and_set());
}

void unlock(std::atomic_flag& m) {
	m.clear();
}

void phil(int ph, std::atomic_flag& ma, std::atomic_flag& mb) {
	while (true) {
		int duration = myrand(1000, 2000);
		syncOutput(std::format("N{0} thinks {1} ms\n", ph, duration));
		std::this_thread::sleep_for(std::chrono::milliseconds(duration));

		lock(ma);
		syncOutput(std::format("\t\tN{} got ma\n", ph));
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		lock(mb);
		syncOutput(std::format("\t\tN{} got mb\n", ph));

		duration = myrand(1000, 2000);
		syncOutput(std::format("\t\t\t\tN{0} eats {1} ms\n", ph, duration));
		std::this_thread::sleep_for(std::chrono::milliseconds(duration));

		unlock(mb);
		unlock(ma);
	}
}


int main() {
	syncOutput("[DINING PHILOSOPHERS] =>\n");
	srand(time(nullptr));

	std::atomic_flag m1, m2, m3, m4;
	unlock(m1);
	unlock(m2);
	unlock(m3);
	unlock(m4);

	std::thread t1([&] { phil(1, m1, m2); });
	std::thread t2([&] { phil(2, m2, m3); });
	std::thread t3([&] { phil(3, m3, m4); });
	std::thread t4([&] { phil(4, m1, m4); });
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
