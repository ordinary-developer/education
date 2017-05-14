#pragma once

class Widget {
    public:
        Widget();
        ~Widget();

    private:
        struct Impl;
        Impl* pImpl;
};
