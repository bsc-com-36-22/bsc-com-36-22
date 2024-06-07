#include <iostream>
#include <string>

int main() {
    int* intPtr = new int;
    std::string* strPtr = new std::string;

    std::cout << "Enter an integer value: ";
    std::cin >> *intPtr;

    std::cout << "Enter a string value: ";
    std::cin.ignore(); // Ignore the newline character in the input buffer
    std::getline(std::cin, *strPtr);

    std::cout << "Dynamically allocated integer value: " << *intPtr << std::endl;
    std::cout << "Dynamically allocated string value: " << *strPtr << std::endl;

    delete intPtr;
    delete strPtr;

    return 0;
}
