#include <iostream>
#inculude <fstream>
using namespace std;
{
   int main (){
    // create and open a text file
    ofstream MyFile("exampleFile.txt");

    //close the file
    MyFile.close();
    return 0;
   }
}