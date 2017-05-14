#pragma once

#include <memory>

class Widget {
    public:
        Widget();
        ~Widget();
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
};
