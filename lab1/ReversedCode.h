#ifndef LAB1_REVERSEDCODE_H
#define LAB1_REVERSEDCODE_H

#include "Bitset.h"

template<size_t n_bits>
class ReversedCode {
private:
    std::bitset<n_bits> bits;

public:
    ReversedCode() = default;
    ReversedCode(const ReversedCode& other) = default;
    ReversedCode(ReversedCode&& other) = default;
    ReversedCode& operator=(const ReversedCode& other) = default;
    ReversedCode& operator=(ReversedCode&& other) = default;

    ReversedCode<n_bits> operator+(const ReversedCode<n_bits> &other) {
        if (other[0] == 1) {

        }
    }
};

#endif //LAB1_REVERSEDCODE_H
