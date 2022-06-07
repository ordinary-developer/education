#ifndef ERASE_LESS_HPP_
#define ERASE_LESS_HPP_

template <class Container>
void erase_less(Container& container) {
    typename Container::iterator prev{ container.end() };
    typename Container::iterator iter{ container.begin() };

    while (container.end() != iter) {
        if (container.end() != prev and not (*prev < *iter))
            iter = container.erase(iter);
        else {
            prev = iter;
            ++iter;
        }
    }
}

#endif
