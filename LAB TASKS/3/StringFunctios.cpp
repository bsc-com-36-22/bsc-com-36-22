#include <iostream> 
#include <cstring>

using namespace std;

int main () {
    char str1[10] = "Hello";
    char str2[10] = "World";
    char str3[10];
    char len;

    //copy str1 into str3
    strcpy (str3,str1);
    cout << "strcpy(str3,str1) : "<<str3<<endl;

    //concatanates str1 and str2 
    strcpy (str1,str2);
    cout << "strcat(str1,str2) : "<<str3<<endl;

    //total length of str1 after concetrantion
    len = strlen(str1);
    cout <<"strlen(str1) "<< len << endl;

    return 0;
    }