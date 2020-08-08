#include <chrono>
#include <functional>

using Time = std::chrono::steady_clock::time_point;

enum class Sound { Beep, Siren, Whistle };

using Duration = std::chrono::steady_clock::duration;

// a dump function
void setAlarm(Time t, Sound s, Duration d) { }

enum class Volume { Normal, Loud, LoudPlusPlus };

// an overloaded function
void setAlarm(Time t, Sound s, Duration d, Volume v) { }

int main() {
    auto setSoundL =
        [](Sound s)
        {
            using namespace std::chrono;
            using namespace std::literals;

            setAlarm(steady_clock::now() + 1h, s, 30s);
        };

    return 0;
}
