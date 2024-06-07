#include <iostream>
using namespace std;

int main() {
    int first, second;
    int* ptr = nullptr;

    // Assign the address of 'first' to the pointer
    ptr = &first;
    *ptr = 1; // Indirection to assign a value to 'first'

    // Assign the address of 'second' to the pointer
    ptr = &second;
    *ptr = 2; // Indirection to assign a value to 'second'

    cout << "first is " << first << endl;
    cout << "second is " << second << endl;

    return 0;
}
