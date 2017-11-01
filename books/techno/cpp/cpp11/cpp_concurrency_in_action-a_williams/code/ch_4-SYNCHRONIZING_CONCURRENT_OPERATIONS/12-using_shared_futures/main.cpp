#include <future>
#include <cassert>

int main() {
    std::promise<int> p;
    std::future<int> f(p.get_future());
    assert(f.valid());

    std::shared_future<int> sf(std::move(f));
    assert(!f.valid());
    assert(sf.valid());

    std::promise<std::string> p2;
    std::shared_future<std::string> sf2(p2.get_future());
    assert(sf2.valid());

    std::promise<std::wstring> p3;
    auto sf3 = p3.get_future().share();
    assert(sf3.valid());

    return 0;
}
