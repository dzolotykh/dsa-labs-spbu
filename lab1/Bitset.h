#ifndef LAB1_BITSET_H
#define LAB1_BITSET_H

#include <cstddef>
#include <array>
#include <bitset>
#include <iostream>

using namespace std;

template<size_t n_bits>
class Bitset {
private:
    std::array<uint64_t, (n_bits + 63) / 64> bits;

public:
    class reference {
        friend class Bitset;
    private:
        uint64_t& segment;
        int8_t bit_number;

        reference(uint64_t& _segment, int8_t _bit_number): segment(_segment), bit_number(_bit_number) {}

    public:
        template<typename T>
        reference& operator=(T value) {
            uint64_t _value = static_cast<bool>(value);
            uint64_t mask = ~(1 << bit_number);
            segment &= mask;
            segment |= (_value << bit_number);

            return *this;
        }

    };

    Bitset() {
        for (auto &i : bits) {
            i = 0;
        }
    };

    bool operator[](size_t index) const {
        return bits[index / 64] & (1 << (index % 64));
    }

    reference operator[](size_t index) {
        return reference(bits[index / 64], index % 64);
    }


    // TODO реализовать оператор +=, оператор + подтянется сам
    Bitset<n_bits>& operator+=(const Bitset<n_bits> &other) {
        uint64_t carry = 0;
        uint64_t mask = ~(uint64_t(1) << 63);
        for (size_t i = 0; i < bits.size(); ++i) {
            uint64_t tmp = bits[i] & mask; // зануляем последний бит
            uint64_t tmp2 = other.bits[i] & mask + carry;
            tmp += tmp2;

            bits[i] += other.bits[i] + carry;
            carry = bits[i] >> 63;
            bits[i] &= ((uint64_t)1 << 63) - 1;
        }
        return *this;
    }

    Bitset<n_bits> operator+(const Bitset<n_bits> &other) {
        Bitset<n_bits> result = *this;
        result += other;
        return result;
    }

    // TODO реализовать оператор *, *= подтянется сам
    Bitset<n_bits>& operator*=(const Bitset<n_bits> &other) {
        return *this;
    }

    Bitset<n_bits> operator * (const Bitset<n_bits> &other) {
        Bitset<n_bits> result = *this;
        result *= other;
        return result;
    }

    Bitset<n_bits> operator~() {
        Bitset<n_bits> result;
        for (size_t i = 0; i < (n_bits + 63) / 64; ++i) {
            result.bits[i] = ~bits[i];
        }
        return result;
    }
};

template<size_t N>
ostream& operator<<(ostream &out, const Bitset<N> &b) {
    for (size_t i = 0; i < N; ++i) {
        out << b[i];
    }
    return out;
}


#endif //LAB1_BITSET_H
