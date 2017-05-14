class Y {
    public:
        Y(Y&) = default; 
        Y& operator=(Y const&) = default;

    protected:
        virtual ~Y() = default;

    private:
        Y() = default;
};

int main() {
    return 0;
}
