```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <ctime>

class Wallet {
private:
    std::string address;
    uint64_t balance;

public:
    Wallet(const std::string& addr, uint64_t initial = 0) : address(addr), balance(initial) {}

    void addFunds(uint64_t amount) {
        balance += amount;
    }

    bool spendFunds(uint64_t amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void print() const {
        std::cout << "Wallet address: " << address << std::endl;
        std::cout << "Balance: " << balance << " CRED" << std::endl;
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        file << address << "\n" << balance << std::endl;
        file.close();
    }

    static Wallet loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string addr;
        uint64_t bal;
        file >> addr >> bal;
        file.close();
        return Wallet(addr, bal);
    }
};

int main() {
    Wallet myWallet("crd1qexampleaddress", 5000000000); // 50 CRED iniziali
    myWallet.print();
    myWallet.spendFunds(1500000000);
    myWallet.addFunds(1000000000);
    myWallet.saveToFile("wallet.dat");

    Wallet loaded = Wallet::loadFromFile("wallet.dat");
    loaded.print();
    return 0;
}
```
