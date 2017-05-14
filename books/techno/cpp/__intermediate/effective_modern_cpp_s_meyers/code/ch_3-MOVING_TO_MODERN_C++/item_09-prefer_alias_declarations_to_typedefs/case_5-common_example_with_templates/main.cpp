class Wine { };

template <typename T>
class MyAllocList { };

template <>
class MyAllocList<Wine> {
    private:
        enum class WineType { White, Red, Rose };
        WineType type;
};

int main() {
}
