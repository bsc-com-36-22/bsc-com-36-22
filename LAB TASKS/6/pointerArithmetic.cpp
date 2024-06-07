#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30};
    int* ptr = nullptr;

    // Assign the address of the first element to the pointer
    ptr = numbers;

    // Print the address of the first element
    cout << "Address of first element: " << ptr << endl;
    cout << "Address of first element: " << &numbers[0] << endl;

    // Print the value of the first element using the pointer
    cout << "Value of first element: " << *ptr << endl;

    // Print the value of the second element using the pointer
    cout << "Value of second element: " << *(++ptr) << endl;

    // Assign the address of the first element to the pointer again
    ptr = numbers;

    // Print the value of the first element using the pointer and post-increment
    cout << "Value of first element: " << *(ptr++) << endl;

    return 0;
}
