namespace my_hash {
template <typename T> 
size_t hash<T>::operator()(T const& key) const {
    size_t bytes{ sizeof(key) };
    size_t res{ 0 };
    for (size_t i{0}; i < bytes; ++i) {
        unsigned char b{ *((unsigned char*)&key + i) };
        res += b;
    }
    return res;
}

size_t hash<std::string>::operator()(std::string const& key) const {
    size_t sum{0};
    for (size_t i{0}; i < key.size(); ++i) 
        sum += (unsigned char)key[i];
    return sum;
}
    
}

