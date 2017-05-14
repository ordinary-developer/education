#include <chrono>
#include <functional>

using Time = std::chrono::steady_clock::time_point;

enum class Sound { Beep, Siren, Whistle };

using Duration = std::chrono::steady_clock::duration;

// a dump function
void setAlarm(Time t, Sound s, Duration d) { }

int main() {
    using namespace std::chrono;
    using namespace std::literals;
    using namespace std::placeholders;

    auto setSoundB = std::bind(setAlarm,
                               std::bind(
                                   std::plus<steady_clock::time_point>(),
                                   steady_clock::now(),
                                   1h),
                               _1,
                               30s);

    return 0;
}
