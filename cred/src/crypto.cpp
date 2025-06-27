#include "crypto.h"
#include <openssl/sha.h>
#include <vector>
#include <stdexcept>

// Calcolo SHA-256 singolo
std::vector<unsigned char> sha256(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> hash(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;

    if (!SHA256_Init(&ctx))
        throw std::runtime_error("SHA256_Init failed");

    if (!SHA256_Update(&ctx, data.data(), data.size()))
        throw std::runtime_error("SHA256_Update failed");

    if (!SHA256_Final(hash.data(), &ctx))
        throw std::runtime_error("SHA256_Final failed");

    return hash;
}

// Calcolo SHA-256 doppio (double hash)
std::vector<unsigned char> double_sha256(const std::vector<unsigned char>& data) {
    return sha256(sha256(data));
}
