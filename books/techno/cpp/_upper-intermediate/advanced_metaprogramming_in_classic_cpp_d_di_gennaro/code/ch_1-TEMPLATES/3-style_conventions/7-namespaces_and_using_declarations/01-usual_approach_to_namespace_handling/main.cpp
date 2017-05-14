namespace framework {
    namespace undocumented_private {
        void handle_with_care() { };
    }

    inline void public_documented_function() {
        undocumented_private::handle_with_care();
    }
}


int main() {
    framework::public_documented_function();

    return 0;
}
