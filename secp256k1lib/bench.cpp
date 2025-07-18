#include <chrono>
#include <vector>
#include <iostream>
#include "secp256k1.h"

using namespace secp256k1;


int main() {
    const int ITER = 100;
    ecpoint g = G();
    std::vector<uint256> keys;
    for(int i = 0; i < ITER; i++) {
        keys.push_back(generatePrivateKey());
    }

    auto start = std::chrono::high_resolution_clock::now();
    for(auto &k : keys) {
        multiplyPoint(k, g);
    }
    auto end = std::chrono::high_resolution_clock::now();
    double optimized = std::chrono::duration<double>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    for(auto &k : keys) {
        multiplyPoint_basic(k, g);
    }
    end = std::chrono::high_resolution_clock::now();
    double basic = std::chrono::duration<double>(end - start).count();

    std::cout << "Optimized: " << optimized << "s" << std::endl;
    std::cout << "Basic: " << basic << "s" << std::endl;

    return 0;
}
