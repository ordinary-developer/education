class Widget {
    public:
        ~Widget() { }

        Widget(const Widget&) = default;

        Widget& operator=(const Widget&) = default;
};

int main() {
    return 0;
}
