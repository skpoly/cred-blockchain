#ifndef CRED_PARAMS_H
#define CRED_PARAMS_H

#include <string>
#include <cstdint>

// Block reward iniziale (in satoshi = 50 CRED)
constexpr uint64_t BLOCK_REWARD = 50 * 100000000;

// Tempo medio tra i blocchi (in secondi)
constexpr uint32_t BLOCK_TIME = 150; // 2.5 minuti

// Halving ogni 500.000 blocchi
constexpr uint32_t HALVING_INTERVAL = 500000;

// Porta default per connessioni P2P
constexpr uint16_t DEFAULT_PORT = 9333;

// Porta default per RPC
constexpr uint16_t DEFAULT_RPC_PORT = 9332;

// Ticker ufficiale
const std::string CURRENCY_TICKER = "CRD";

// Indirizzo Bech32 (simbolico – solo decorativo se non usi encoder Bech32)
const std::string ADDRESS_PREFIX = "crd1";

// Genesis Block hash (da `generate_genesis.py`)
const std::string GENESIS_HASH = "0000059a50f017b22971397346089d5314a77c1dc0c23e5759d5e351422c7291";

// Nonce corrispondente al Genesis Block
constexpr uint32_t GENESIS_NONCE = 566762;

// Timestamp blocco Genesis
constexpr uint32_t GENESIS_TIMESTAMP = 1747961125; // 22/05/2025 22:05:25 UTC

#endif // CRED_PARAMS_H
