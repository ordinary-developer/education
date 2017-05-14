#include "PacketBuffer.hpp"


#include <iostream>


class IPPacket {
    public:
        IPPacket(int id) : _id(id) { }
        int getID() const { return _id; }
    private:
        int _id;
};


auto main() -> int {
    PacketBuffer<IPPacket> ipPackets(3);

    for (int i = 1; i <= 4; ++i) {
        if (!ipPackets.bufferPacket(IPPacket(i))) {
            std::cout << "Packet " << i << " dropped (queue is full)." 
                      << std::endl;
        }
    }

    while (true) {
        try {
            IPPacket packet = ipPackets.getNextPacket();
            std::cout << "Processing the packet: " << packet.getID()
                      << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "The queue is empty." << std::endl;
            break;
        }
    }

    return 0;
}
