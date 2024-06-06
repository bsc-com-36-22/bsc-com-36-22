#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char data[100];

    // Open a text file in write mode.
    ofstream outfile;
    outfile.open("a file.txt");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl;

    // Close the opened file.
    outfile.close();

    // Open a text file in read mode.
    ifstream infile;
    infile.open("a file.txt");

    cout << "Reading from the file" << endl;
    infile >> data;
    cout << data << endl;

    infile >> data;
    cout << data << endl;

    // Close the opened file.
    infile.close();

    return 0;
}
