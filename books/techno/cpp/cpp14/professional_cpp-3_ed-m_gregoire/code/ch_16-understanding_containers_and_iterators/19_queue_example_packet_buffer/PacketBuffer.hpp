#ifndef PACKET_BUFFER_HPP
#define PACKET_BUFFER_HPP


#include <cstddef>
#include <queue>
#include <stdexcept>


template <typename T>
class PacketBuffer {
    public:
        PacketBuffer(size_t maxSize = 0);
        bool bufferPacket(const T& packet);
        T getNextPacket();
    private:
        size_t _maxSize;
        std::queue<T> _packets;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize) 
    : _maxSize(maxSize) { }

template <typename T>
bool PacketBuffer<T>::bufferPacket(const T& packet) {
    if (_maxSize > 0 && _packets.size() == _maxSize) {
        return false;
    }
    _packets.push(packet);
    return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket() {
    if (_packets.empty()) {
        throw std::out_of_range("Buffer is empty");
    }
    T temp = _packets.front();
    _packets.pop();
    return temp;
}

#endif
