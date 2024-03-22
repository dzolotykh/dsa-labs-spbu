#include <iostream>
#include <vector>
#include "ReversedCode.h"

using namespace std;

struct Test {
    int a;
    int b;
    enum class OperationType { ADD, SUB, MUL } operation;

    Test(int a, int b, OperationType operation)
        : a(a), b(b), operation(operation) {}
};

void test() {
    vector<Test> test = {
        {5, 10, Test::OperationType::ADD},   {3, -2, Test::OperationType::SUB},
        {-3, 2, Test::OperationType::MUL},   {1, -4, Test::OperationType::ADD},
        {100, -20, Test::OperationType::SUB},  {-200, 5, Test::OperationType::MUL},
        {-343, -15, Test::OperationType::ADD},  {-111, 222, Test::OperationType::SUB},
        {228, 1337, Test::OperationType::MUL},  {-22, 8, Test::OperationType::ADD},
        {13, 37, Test::OperationType::SUB}, {-5, -2, Test::OperationType::MUL},
    };

    int accepted = 0;

    for (auto [_a, _b, operation] : test) {
        ReversedCode<int> a = _a;
        ReversedCode<int> b = _b;
        switch (operation) {
            case Test::OperationType::ADD:
                if (static_cast<int>(a + b) != _a + _b) {
                    cout << "Error: " << a << " + " << b << " = " << a + b
                         << " != " << _a + _b << endl;
                } else {
                    accepted++;
                }
                break;
            case Test::OperationType::SUB:
                if (static_cast<int>(a - b) != _a - _b) {
                    cout << "Error: " << a << " - " << b << " = " << a - b
                         << " != " << _a - _b << endl;
                } else {
                    accepted++;
                }
                break;
            case Test::OperationType::MUL:
                if (static_cast<int>(a * b) != _a * _b) {
                    cout << "Error: " << a << " * " << b << " = " << a * b
                         << " != " << _a * _b << endl;
                } else {
                    accepted++;
                }
                break;
        }
    }
    cout << "Accepted: " << accepted << " / " << test.size() << endl;
}

int main() {
    test();
}