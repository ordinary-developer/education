constexpr int getArraySize() { return 32; }

class Rect {
    public:
        constexpr Rect(int width, int height)
            :mWidth(width), mHeight(height) { }
        constexpr int getArea() const { return mWidth * mHeight; }
    private:
        int mWidth, mHeight;
};

auto main() -> int {
    int myArray[getArraySize()];

    constexpr Rect r(8, 2);
    int myarray[r.getArea()];

    return 0;
}
