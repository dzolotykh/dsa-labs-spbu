#include <iostream>

using namespace std;

void print(int a) {
    int cnt = 32;
    for (int i = 0; i < 32; i++) {
        cout << a % 2;
        a /= 2;
    }
}

int main() {
}
