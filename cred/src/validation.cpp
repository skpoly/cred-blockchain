```cpp
#include "block.h"
#include "validation.h"
#include "crypto.h"
#include <iostream>

bool isValidProofOfWork(const Block& block) {
    std::string hash = block.getHash();
    std::string targetPrefix = "00000"; // Adjust for network difficulty
    return hash.substr(0, targetPrefix.length()) == targetPrefix;
}

bool validateBlock(const Block& block, const std::string& prevBlockHash) {
    if (block.getHash().empty()) {
        std::cerr << "[ERROR] Block hash is empty." << std::endl;
        return false;
    }

    if (block.getHash() == prevBlockHash) {
        std::cerr << "[ERROR] Block hash matches previous block hash." << std::endl;
        return false;
    }

    if (!isValidProofOfWork(block)) {
        std::cerr << "[ERROR] Block does not satisfy proof of work." << std::endl;
        return false;
    }

    return true;
}
```