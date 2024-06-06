#include <iostream> 
#include <cstring>

using namespace std;

int main () {
    string str1[10] = "Hello";
    string str2[10] = "World";
    string str3[10];
   string len;

    //copy str1 into str3
    str3 (str3,str1);
    cout << "str3 : "<<str3<<endl;

    //concatanates str1 and str2 
    str3 = str1 + str2;
    cout << "str1 + str2 : "<<str3<<endl;

    //total length of str1 after concetrantion
    len = str3.size();
    cout <<"str3.size() "<< len << endl;

    return 0;
    }