class my_class { };

my_class& get_my_class_instance() {
    static my_class instance;
    return instance;
}

int main() {
    return 0;
}
