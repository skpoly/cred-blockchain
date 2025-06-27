#!/bin/bash

echo ">> [CRED BUILD] Avvio compilazione nodo CRED..."

# 1. Aggiorna sistema e installa dipendenze
echo ">> [Step 1/4] Installazione pacchetti richiesti..."
sudo apt update && sudo apt install -y \
    build-essential libtool autotools-dev automake pkg-config bsdmainutils curl \
    libevent-dev libboost-system-dev libboost-filesystem-dev libboost-test-dev \
    libboost-thread-dev libssl-dev libdb-dev libdb++-dev \
    libminiupnpc-dev libzmq3-dev git

# 2. Configura ambiente di build
echo ">> [Step 2/4] Generazione script di configurazione..."
./autogen.sh

# 3. Configura i flag per la build (disattiva wallet per build leggera, opzionale)
echo ">> [Step 3/4] Configurazione Makefile..."
./configure --without-gui --disable-tests

# 4. Compila il progetto
echo ">> [Step 4/4] Compilazione del nodo..."
make -j$(nproc)

# Fine
if [ $? -eq 0 ]; then
    echo "✅ Compilazione completata con successo."
    echo "➡️ Nodo disponibile in: ./src/credd"
else
    echo "❌ Errore durante la compilazione."
    exit 1
fi
