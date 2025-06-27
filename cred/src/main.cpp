```cpp
#include "block.h"
#include "validation.h"
#include <iostream>
#include <ctime>

int main() {
    Block genesis(
        1,
        std::string(64, '0'), // previous hash (all zeros)
        "4b8e3d930c...",       // merkle root (placeholder)
        1747934725,           // timestamp (fixed or time(nullptr))
        0x1e0ffff0,           // difficulty bits
        566762                // nonce
    );

    std::cout << "CRED Blockchain - Genesis Block" << std::endl;
    genesis.print();

    if (validateBlock(genesis, std::string(64, '0')))
        std::cout << "Genesis block is valid." << std::endl;
    else
        std::cout << "Genesis block is invalid." << std::endl;

    return 0;
}
```