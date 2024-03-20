#include <iostream>
#include "Bitset.h"

using namespace std;

void test1() {
    Bitset<128> bits1;
    bits1[1] = 1;
    bits1[0] = 1;
    Bitset<128> bits2;
    bits2[2] = 1;

    cout << bits1 << endl;
    cout << bits2 << endl;

    cout << (bits1 + bits2) << endl;
}

void print(int a) {
    int cnt = 32;
    for (int i = 0; i < 32; i++) {
        cout << a % 2;
        a /= 2;
    }
}

int main() {
    // test1();
    int a = ~(1 << 31);
    print(a);

}
