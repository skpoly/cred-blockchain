#ifndef CRED_CRYPTO_H
#define CRED_CRYPTO_H

#include <vector>

// Funzione per calcolo SHA-256 singolo
std::vector<unsigned char> sha256(const std::vector<unsigned char>& data);

// Funzione per calcolo SHA-256 doppio
std::vector<unsigned char> double_sha256(const std::vector<unsigned char>& data);

#endif // CRED_CRYPTO_H
