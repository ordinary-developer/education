class no_copies {
    public:
        no_copies() { }
    
    private:
        no_copies(const no_copies&);
        no_copies& operator = (const no_copies&);
};

int main() {
    no_copies(a);
    // will not compile
    // no_copies b(a);
}
