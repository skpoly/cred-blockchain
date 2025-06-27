```cpp
#ifndef CRED_BLOCK_H
#define CRED_BLOCK_H

#include <string>

class Block {
public:
    Block(uint32_t version, const std::string& prevHash, const std::string& merkleRoot,
          uint32_t timestamp, uint32_t bits, uint32_t nonce);

    std::string getHeader() const;
    std::string getHash() const;
    void print() const;

private:
    uint32_t version;
    std::string prevHash;
    std::string merkleRoot;
    uint32_t timestamp;
    uint32_t bits;
    uint32_t nonce;
};

#endif // CRED_BLOCK_H
```

---
