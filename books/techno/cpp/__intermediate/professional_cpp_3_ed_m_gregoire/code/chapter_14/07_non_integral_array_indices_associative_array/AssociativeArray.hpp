#ifndef ASSOCIATIVE_ARRAY_HPP
#define ASSOCIATIVE_ARRAY_HPP

#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
class AssociativeArray {
    public:
        AssociativeArray();
        virtual ~AssociativeArray();

        T& operator [] (const std::string& key);
        const T& operator [] (const std::string& key) const;
    private:
        class Element {
            public:
                Element(const std::string& key, const T& value) 
                    : mKey(key), mValue(value) { }
                std::string mKey;
                T mValue;
        };

        std::vector<Element> mData;
};

template <typename T> AssociativeArray<T>::AssociativeArray() { }

template <typename T> AssociativeArray<T>::~AssociativeArray() { }

template <typename T> 
T& AssociativeArray<T>::operator [] (const std::string& key) {
    for (auto& element : mData) {
        if (key == element.mKey) {
            return element.mValue;
        }
    }
    return mData.insert(end(mData), Element(key, T()))->mValue;
}

template <typename T>
const T& AssociativeArray<T>::operator [] (const std::string& key) const {
    for (auto& element : mData) {
        if (key == element.mKey) {
            return element.mValue;
        }
    }
    throw std::invalid_argument("Key '" + key + "' doesn't exist");
}
#endif
