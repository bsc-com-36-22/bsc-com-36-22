#include <iostream>
using namespace std;

int main() {
    int numElements;
    int* data;

    cout << "Enter the number of elements: ";
    cin >> numElements;

    // Dynamically allocate memory for the array
    data = new int[numElements];

    // Check if memory allocation was successful
    if (data == nullptr) {
        cout << "Error: Unable to allocate memory." << endl;
        return 1;
    }

    // Get input from the user and store it in the array
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < numElements; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> data[i];
    }

    // Print the elements of the array
    cout << "The elements are: ";
    for (int i = 0; i < numElements; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Free the dynamically allocated memory
    delete[] data;

    return 0;
}
