class Base {
    public:
        virtual ~Base() = default;

        Base(Base&&) = default;
        Base& operator= (Base&&) = default;

        Base(const Base&) = default;
        Base& operator=(const Base&) = default;
};

int main() {
    return 0;
}
