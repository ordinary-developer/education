#include <cstdint>
#include <memory>

void f(std::size_t sz) { }

temlate <typename... Ts>
void f(Ts&&... params)
{
    f(std::forward<Ts>(params)...);
}

struct IPv4Header {
    std::uint32_t version:4,
                  IHL:4,
                  DSCP:6,
                  ECN:2,
                  totalLength:16;
};

int main() {
    IPv4Header h;
    // Ok
    f(h.totalLength);

    // not fine
    // fwd(h.totalLength);
    auto length = static_cast<std::uint16_t>(h.totalLength);
    fwd(length);

    return 0;
}
