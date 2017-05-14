#pragma once

#include <memory>

class Widget {
    public:
        Widget();

    private:
        struct Impl;
        std::shared_ptr<Impl> pImpl;
};
