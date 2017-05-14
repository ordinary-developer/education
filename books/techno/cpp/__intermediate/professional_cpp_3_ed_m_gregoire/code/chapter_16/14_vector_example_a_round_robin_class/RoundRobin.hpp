#ifndef ROUND_ROBIN_HPP
#define ROUND_ROBIN_HPP

#include <cstddef>
#include <stdexcept>
#include <vector>


template <typename T>
class RoundRobin {
    public:
        RoundRobin(size_t mumExpected = 0);
        virtual ~RoundRobin();

        RoundRobin(const RoundRobin& src) = delete;
        RoundRobin& operator = (const RoundRobin& rhs) = delete;

        void add(const T& elem);
        void remove(const T& elem);
        T& getNext();
    private:
        std::vector<T> mElems;
        typename std::vector<T>::iterator mCurElem;
};


template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected) {
    mElems.reserve(numExpected);
    mCurElem = end(mElems);
}

template <typename T>
RoundRobin<T>::~RoundRobin() { }

template <typename T>
void RoundRobin<T>::add(const T& elem) {
    int pos = (mCurElem == end(mElems) ? -1 : mCurElem - begin(mElems));
    mElems.push_back(elem);
    mCurElem = (pos == -1 ? end(mElems) : begin(mElems) + pos);
}

template <typename T>
void RoundRobin<T>::remove(const T& elem) {
    for (auto it = begin(mElems); it != end(mElems); ++it) {
        if (*it == elem) {
            int newPos;
            if (mCurElem <= it) {
                newPos = mCurElem - begin(mElems);
            }
            else {
                newPos = mCurElem - begin(mElems) - 1;
            }
            mElems.erase(it);
            mCurElem = begin(mElems) + newPos;
            return;
        }
    }
}

template <typename T>
T& RoundRobin<T>::getNext() { 
    if (mElems.empty()) {
        throw std::out_of_range("No elements in the list");
    }
    if (end(mElems) == mCurElem) {
        mCurElem = begin(mElems);
    }
    else {
        ++mCurElem;
        if (end(mElems) == mCurElem) {
            mCurElem = begin(mElems);
        }
    }
    return *mCurElem;
}

#endif
