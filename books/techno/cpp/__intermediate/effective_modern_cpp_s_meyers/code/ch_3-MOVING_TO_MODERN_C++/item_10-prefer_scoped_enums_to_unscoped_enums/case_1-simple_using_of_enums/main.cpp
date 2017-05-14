// old C++98 style
enum _Color { _black, _white, _red };

enum class Color { black, white, red };

int main() {
    auto _white = false;

    auto white = false;
    // here an error will be
    // Color c = white;
    Color c1 = Color::white;
    auto c2 = Color::white;
}
