#pragma once

#include <iostream>
#include <iterator>
#include <ostream>
#include <string>


void trace(std::string const& msg) { std::cout << msg << '\n'; }

template <class Kind>
class iterator_advancer {
    public:
        template <class InIter, class Distance>
        void operator()(InIter& iter, Distance distance) {
            trace("iterator_advance<>");
            for ( ; 0 != distance; --distance)
                ++iter;
        }
};

template <>
class iterator_advancer<std::bidirectional_iterator_tag> {
    public:
        template <class BiDiIter, class Distance>
        void operator()(BiDiIter& iter, Distance distance) {
            trace("iterator_advancer<bidirectional_iterator_tag>");
            if (distance < 0)
                for (/*empty*/ ; 0 != distance; ++distance)
                    --iter;
            else
                for (/*empty*/ ; 0 != distance; --distance)
                    ++iter;
        }
};

template <>
class iterator_advancer<std::random_access_iterator_tag> {
    public:
        template <class RandomIter, class Distance>
        void operator()(RandomIter& iter, Distance distance) {
            trace("iterator_advancer<random_access_iterator_tag>");
            iter += distance;
        }
};

template <class InIter, class Distance>
void my_advance(InIter& iter, Distance distance) {
    iterator_advancer<
        typename 
            std::iterator_traits<InIter>::iterator_category>{}(iter,
                                                               distance);
}
