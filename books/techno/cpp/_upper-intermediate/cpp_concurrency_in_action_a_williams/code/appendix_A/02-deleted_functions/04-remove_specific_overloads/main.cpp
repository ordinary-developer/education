void foo(short) { }
void foo(int) = delete;

int main() {
    // error
    // foo(42);
    
    // OK
    foo((short)42);
    return 0;
}
