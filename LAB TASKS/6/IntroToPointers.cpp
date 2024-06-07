#include <iostream>
using namespace std;

int main() {
    int value = 5;
    int* ptr = nullptr;

    // Assign the address of the variable 'value' to the pointer 'ptr'
    ptr = &value;

    // Print the value of the variable 'value'
    cout << "Value: " << value << endl;

    // Print the address of the variable 'value'
    cout << "Address of Value: " << &value << endl;

    // Print the value of the pointer 'ptr'
    cout << "Pointer: " << ptr << endl;

    // Print the address of the pointer 'ptr'
    cout << "Address of Pointer: " << &ptr << endl;

    return 0;
}
