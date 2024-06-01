#include <iostream>
#include <string>
using namespace std;

int main(){
     int* dynamicInt = new int;
     string*  dynamicString = new string;

     cout<< "enter the interger value"<<endl;
     cin>> * dynamicInt;

     
     cout<< "enter  stringvalue"<<endl;
     cin>> * dynamicString;

     cout <<"valueof imnterger is" << *dynamicInt << endl;
        cout <<"stringoutput is" << *dynamicString << endl;

        delete dynamicInt;
        delete dynamicString;

        return 0;




     

}