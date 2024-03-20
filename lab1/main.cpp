#include <iostream>
#include "Bitset.h"

using namespace std;

void test1() {
    Bitset<128> bits1;
    bits1[1] = 1;

    cout << bits1 << endl;

}

void print(int a) {
    int cnt = 32;
    for (int i = 0; i < 32; i++) {
        cout << a % 2;
        a /= 2;
    }
}

int main() {
    test1();

}
