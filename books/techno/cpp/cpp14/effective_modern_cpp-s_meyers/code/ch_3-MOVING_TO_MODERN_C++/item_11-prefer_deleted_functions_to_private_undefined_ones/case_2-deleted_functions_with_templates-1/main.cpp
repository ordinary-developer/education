template <typename T>
void processPointer(T* ptr);

template <>
void processPointer<void>(void*) = delete;

template <>
void processPointer<char>(char*) = delete;

template <>
void processPointer<const void>(const void*) = delete;

template <>
void processPointer<const char>(const char*) = delete;

int main() {
}
