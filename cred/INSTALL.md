# Installation Guide – CRED Blockchain Node

This guide explains how to build and run the CRED blockchain node from source.

---

##  Requirements

Make sure you're using **Ubuntu 22.04 or later**.

Install the required system packages:

```bash
sudo apt update
sudo apt install -y \
  build-essential libssl-dev libcrypto++-dev libboost-all-dev \
  libtool autotools-dev automake pkg-config git
