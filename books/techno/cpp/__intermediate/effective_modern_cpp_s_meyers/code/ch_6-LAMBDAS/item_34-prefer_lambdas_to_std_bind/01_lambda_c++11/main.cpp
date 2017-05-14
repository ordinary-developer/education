#include <chrono>

using Time = std::chrono::steady_clock::time_point;

enum class Sound { Beep, Siren, Whistle };

using Duration = std::chrono::steady_clock::duration;

// a dump function
void setAlarm(Time t, Sound s, Duration d) { }

int main() {
    auto setSoundL =
        [] (Sound s)
        {
            using namespace std::chrono;
            setAlarm(steady_clock::now() + hours(1),
                     s,
                     seconds(30));
        };

    return 0;
}
