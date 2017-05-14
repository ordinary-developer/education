#include <cstdint>

// here for unscoped enums forward declaration is allowed
enum  UnscopedStatus: std::uint32_t;

// here for scoped enums forward declaration is allowed
enum class ScopedStatus: std::uint32_t { good = 0,
                                         failed = 1,
                                         incomplete = 100,
                                         corrupt = 200,
                                         audited = 500,
                                         indeterminate = 0xFFFFFFFF
                                       };       

int main() {
}
