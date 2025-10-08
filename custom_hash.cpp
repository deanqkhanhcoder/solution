#include <iostream>
#include <chrono>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RANDOM;
        x ^= (x >> 23) ^ (x << 16);
        return x;
    }
};


