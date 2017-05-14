// forward-declaration for old enums
// a compilation error will be
// enum UnscopedColor;

// no errors
enum UnscopedColor { black, white, red };


// forward declaratios for new enums
// fine
enum class ScopedColor;

int main() {
}
