```cpp
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

class Peer {
public:
    std::string ip;
    int port;

    Peer(const std::string& ip, int port) : ip(ip), port(port) {}

    void connect() {
        std::cout << "Connecting to peer: " << ip << ":" << port << std::endl;
    }
};

class Node {
private:
    std::vector<Peer> peers;
    std::mutex peer_mutex;

public:
    void addPeer(const std::string& ip, int port) {
        std::lock_guard<std::mutex> lock(peer_mutex);
        peers.emplace_back(ip, port);
    }

    void startNetwork() {
        std::cout << "Starting node network..." << std::endl;
        for (auto& peer : peers) {
            std::thread(&Peer::connect, &peer).detach();
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Node online with " << peers.size() << " peers." << std::endl;
    }
};

int main() {
    Node node;
    node.addPeer("192.168.1.10", 8333);
    node.addPeer("192.168.1.11", 8333);
    node.startNetwork();
    return 0;
}
```