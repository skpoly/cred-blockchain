```cpp
#include <iostream>
#include <string>
#include <cstring>
#include <openssl/sha.h>

bool checkProofOfWork(const std::string& hashHex, int difficultyPrefixZeros) {
    for (int i = 0; i < difficultyPrefixZeros; ++i) {
        if (hashHex[i] != '0') return false;
    }
    return true;
}

std::string sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);

    char buf[2 * SHA256_DIGEST_LENGTH + 1];
    buf[2 * SHA256_DIGEST_LENGTH] = 0;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buf + i * 2, "%02x", hash[i]);
    }
    return std::string(buf);
}

int main() {
    std::string data = "test block";
    std::string hash = sha256(data);

    std::cout << "Hash: " << hash << std::endl;
    if (checkProofOfWork(hash, 5)) {
        std::cout << "Valid PoW" << std::endl;
    } else {
        std::cout << "Invalid PoW" << std::endl;
    }
    return 0;
}
```
