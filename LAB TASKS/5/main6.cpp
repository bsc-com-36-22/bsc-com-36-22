#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int countVowels(const string& text) {
    int count = 0;
    for(char c : text) {
        if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            count++;
        }
    }
    return count;
}

int countWords(const string& text) {
    int count = 0;
    bool inWord = false;
    for(char c : text) {
        if(isalpha(c) && !inWord) {
            count++;
            inWord = true;
        } else if(!isalpha(c) && inWord) {
            inWord = false;
        }
    }
    return count;
}

string reverseString(const string& text) {
    return string(text.rbegin(), text.rend());
}

string capitalizeSecondLetter(const string& text) {
    string result = text;
    for(size_t i = 1; i < result.size(); i++) {
        if(isspace(result[i - 1])) {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

int main() {
    ifstream file("file.txt");
    if(!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string fileData;
    getline(file, fileData);

    int numVowels = countVowels(fileData);
    cout << "Number of vowels: " << numVowels << endl;

   
    int numWords = countWords(fileData);
    cout << "Number of words: " << numWords << endl;

    string reversedStatement = reverseString(fileData);
    cout << "Reversed statement: " << reversedStatement << endl;

   
    string capitalizedStatement = capitalizeSecondLetter(fileData);
    cout << "Capitalized statement: " << capitalizedStatement << endl;

    return 0;
}
