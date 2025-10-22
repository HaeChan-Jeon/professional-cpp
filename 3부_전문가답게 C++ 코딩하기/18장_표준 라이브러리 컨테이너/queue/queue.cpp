#include <iostream>
#include <queue>

template <typename T>
class PacketBuffer
{
    public:
        explicit PacketBuffer(size_t maxSize = 0);

        virtual ~PacketBuffer() = default;

        bool bufferPacket(const T& packet);

        [[nodiscard]] T getNextPacket();

    private:
        std::queue<T> m_packets;
        size_t m_maxSize;
};

template <typename T> PacketBuffer<T>::PacketBuffer(size_t maxSize)
    : m_maxSize{ maxSize }
{
}

template <typename T> bool PacketBuffer<T>::bufferPacket(const T& packet)
{
    if (m_maxSize > 0 && m_packets.size() == m_maxSize) {
        return false;
    }
    m_packets.push(packet);
    return true;
}

template <typename T> T PacketBuffer<T>::getNextPacket()
{
    if (m_packets.empty()) {
        throw std::out_of_range{ "Buffer is empty" };
    }
    T temp{ m_packets.front() };
    m_packets.pop();
    return temp;
}

class IPPacket final
{
    public:
        explicit IPPacket(int id) : m_id { id } {}
        int getID() const { return m_id; }
    private:
        int m_id;
};

int main()
{
    PacketBuffer<IPPacket> ipPackets{ 3 };

    for (int i{ 1 }; i <= 4; ++i) {
        if (!ipPackets.bufferPacket(IPPacket { i })) {
            std::cout << "packet " << i << " dropped (queue is full)." << std::endl;
        }
    }

    while (true) {
        try {
            IPPacket packet{ ipPackets.getNextPacket() };
            std::cout << "Processing packet " << packet.getID() << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Queue is empty" << std::endl;
            break;
        }
    }
}