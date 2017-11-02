#include <iostream>
namespace example01 {

template <typename RESTYPE>
class ScopedResource final {
    public:
        ScopedResource() { managedResource_ = new RESTYPE(); }
        ~ScopedResource() { delete managedResource_; } 

        RESTYPE* operator->() const { return managedResource_; }
    private:
        RESTYPE* managedResource_;
};

struct Resource {
    void foo() { std::cout << "ResourceInstance::foo" << std::endl; }    
};

void run() {
    try
    {
        ScopedResource<Resource> scopedResource{};
        scopedResource->foo();
    }
    catch (...) { throw; }
}
} // namespace example1

#include <iostream>
#include <memory>
namespace example02 {
struct Resource {
    void foo() { std::cout << "ResourceInstance::foo" << std::endl; }
};

void run() {
    std::unique_ptr<Resource> resource1{ std::make_unique<Resource>() };
    resource1->foo();

    auto resource2{ std::make_unique<Resource>() };
    resource2->foo();
}
} // namespace example02

#include <iostream>
#include <memory>
#include <vector>
namespace example03 {

struct Resource {};

void run() {
    using ResourcePtr = std::unique_ptr<Resource>;
    using ResourceVector = std::vector<ResourcePtr>;

    ResourcePtr resource{ std::make_unique<Resource>() };
    ResourceVector aCollectionOfResources{};
    aCollectionOfResources.push_back(std::move(resource));
}
} // namespace example03

#include <iostream>
#include <memory>
namespace example04 {

class ResourceType {};

void run() {
    std::unique_ptr<ResourceType> pointer1 = 
        std::make_unique<ResourceType>();
    std::unique_ptr<ResourceType> pointer2{};
    pointer2 = std::move(pointer1);
}
} // namespace example04

#include <iostream>
#include <memory>
namespace example05 {

class ResourceType {};

void run() {
    std::shared_ptr<ResourceType> pointer1 =
        std::make_shared<ResourceType>();
    std::shared_ptr<ResourceType> pointer2{};

    pointer2 = std::move(pointer1);
}
} // namespace example05

#include <iostream>
#include <memory>
namespace example06 {

class ResourceType {};

void doSomething(std::weak_ptr<ResourceType> const& weakResource) {
    if (not weakResource.expired()) {
        std::cout << "weakResource is valid" << std::endl;
        std::shared_ptr<ResourceType> sharedResource = weakResource.lock();
    }
    else
        std::cout << "weakResource is invalid" << std::endl;
}

void run() {
    auto sharedResource{ std::make_shared<ResourceType>() };
    std::weak_ptr<ResourceType> weakResource(sharedResource);
    doSomething(weakResource);
    sharedResource.reset();
    doSomething(weakResource);
}
} // namespace example06

#include <iostream>
#include <memory>
namespace example07 {
class B;

class A {
    public:
        void setB(std::shared_ptr<B>& pointerToB) {
            pointerToB_ = pointerToB;
        }

    private:
        std::weak_ptr<B> pointerToB_;
};

class B {
    public:
        void setA(std::shared_ptr<A>& pointerToA) {
            pointerToA_ = pointerToA;
        }

    private:
        std::weak_ptr<A> pointerToA_;
};

void run() {
    {
        auto pointerToA{ std::make_shared<A>() };
        auto pointerToB{ std::make_shared<B>() };
        pointerToA->setB(pointerToB);
        pointerToB->setA(pointerToA);
    }
}
} // namespace example07

#include <iostream>
namespace example08 {
    
// simulation of win32 HANDLE 
using HANDLE = void*;

HANDLE OpenHandle() {
    void* p = new int{1};
    return p;
}

void CloseHandle(HANDLE handle) {
    if (nullptr != handle)
        delete handle;
}

class Win32HandleCloser {
    public:
        void operator()(HANDLE handle) const {
            CloseHandle(handle);
        }
};

using Win32SharedHandle = std::shared_ptr<void>;

void run() {
    Win32SharedHandle processHandle{ OpenHandle(), Win32HandleCloser() };
}

} // namespace example08


int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();
    example08::run();

    return 0;
}
