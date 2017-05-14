class Widget1 {
    public:
        template <typename T>
        void processPointer(T* ptr) 
        { 
        }
    private:
        // here a compilation error will be
        // template <>
        // void processPointer<void>(void*);
};

class Widget2 {
    public:
        template <typename T>
        void processPointer(T* ptr)
        {
        }
};
// still public, but deleted
template <>
void Widget2::processPointer<void>(void*) = delete;


int main() {
}
