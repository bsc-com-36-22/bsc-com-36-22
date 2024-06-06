#include <iostream>

using namespace std;

main() {
    int a =21;
    int c;

    c= a;
    cout << "Line 1 - = operator,value of c = : " <<c<< endl;

    c += a;
    cout << "Line 2 - += operator,value of c = : " <<c<< endl;

    c -= a;
    cout << "Line 3 - -= operator,value of c = : " <<c<< endl;

    c *= a;
    cout << "Line 4 - *= operator,value of c = : " <<c<< endl;

    c /= a;
    cout << "Line 5 - /= operator,value of c = : " <<c<< endl;
    
    c = 200;
    c %= a;
    cout << "Line 6 - %= operator,value of c = : " <<c<< endl;

    c<<=2;
    cout << "Line 7 - <<= operator,value of c = : " <<c<< endl;

    c >>=2;
    cout << "Line 8 - >>= operator,value of c = : " <<c<< endl;

    c &= 2;
    cout << "Line 9 - &= operator,value of c = : " <<c<< endl;

    c ^= 2;
    cout << "Line 10 - ^= operator,value of c = : " <<c<< endl;

    c |= 2;
    cout << "Line 11 - |= operator,value of c = : " <<c<< endl;
     
     return 0;
}