class no_copies {
    public:
        no_copies() { }
        no_copies(const no_copies&) = delete;
        no_copies& operator = (const no_copies&) = delete;
};

int main() {
    no_copies a;
    // can not be compiled
    // no_copies b(a);

    return 0;
}
