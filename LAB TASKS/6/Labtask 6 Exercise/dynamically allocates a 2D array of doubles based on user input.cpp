#include <iostream>

int main() {
    int r, c;

    // Get the number of rows and columns from the user
    do {
        std::cout << "Enter the number of rows (1-3): ";
        std::cin >> r;
    } while (r < 1 || r > 3);

    do {
        std::cout << "Enter the number of columns (1-3): ";
        std::cin >> c;
    } while (c < 1 || c > 3);

    // Dynamically allocate the 2D array
    double** arr = new double*[r];
    for (int i = 0; i < r; i++) {
        arr[i] = new double[c];
    }

    // Fill the array with user input
    std::cout << "Enter the array elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> arr[i][j];
        }
    }

    // Print the array
    std::cout << "The array:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Deallocate the memory
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
