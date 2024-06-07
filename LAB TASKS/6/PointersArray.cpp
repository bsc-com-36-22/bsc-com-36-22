#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int* ptr = nullptr;

    // Assign the address of the first element to the pointer
    ptr = numbers;
    *ptr = 10; // Assign a value to the first element

    // Increment the pointer to assign a value to the second element
    *(++ptr) = 20;

    // Assign the address of the third element to the pointer
    ptr = &numbers[2];
    *ptr = 30;

    // Assign the address of the fourth element to the pointer using pointer arithmetic
    ptr = numbers + 3;
    *ptr = 40;

    // Assign a value to the fifth element using indirection and pointer arithmetic
    *(numbers + 4) = 50;

    // Iterate and output all the elements in the array
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}
