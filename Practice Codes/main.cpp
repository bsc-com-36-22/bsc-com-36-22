#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int userInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Please enter an integer value between 5 and 10: ";
        string inputStr;
        getline(cin, inputStr);

        // Convert string input to integer
        istringstream iss(inputStr);
        if (iss >> userInput) {
            if (userInput >= 5 && userInput <= 10) {
                validInput = true;
            } else {
                cout << "Invalid input. Please enter an integer value between 5 and 10." << endl;
            }
        } else {
            cout << "Invalid input. Please enter an integer value between 5 and 10." << endl;
        }
    }

    cout << "Your input value (" << userInput << ") has been accepted." << endl;

    return 0;
}
