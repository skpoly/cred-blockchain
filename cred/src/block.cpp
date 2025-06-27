```cpp
#include "block.h"
#include "crypto.h"
#include "params.h"
#include <iostream>
#include <sstream>

Block::Block(uint32_t version, const std::string& prevHash, const std::string& merkleRoot,
             uint32_t timestamp, uint32_t bits, uint32_t nonce)
    : version(version), prevHash(prevHash), merkleRoot(merkleRoot),
      timestamp(timestamp), bits(bits), nonce(nonce) {}

std::string Block::getHeader() const {
    std::ostringstream ss;
    ss << version << prevHash << merkleRoot << timestamp << bits << nonce;
    return ss.str();
}

std::string Block::getHash() const {
    return sha256d(getHeader());
}

void Block::print() const {
    std::cout << "Block Hash: " << getHash() << std::endl;
    std::cout << "Version: " << version << std::endl;
    std::cout << "Previous Hash: " << prevHash << std::endl;
    std::cout << "Merkle Root: " << merkleRoot << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Bits: " << bits << std::endl;
    std::cout << "Nonce: " << nonce << std::endl;
}
```

---