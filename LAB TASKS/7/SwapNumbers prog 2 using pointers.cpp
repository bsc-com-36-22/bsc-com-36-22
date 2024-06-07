#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 25;
    int y = 100;

    cout << "x before swap: " << x << endl;
    cout << "y before swap: " << y << endl;

    Swap(&x, &y);

    cout << "x after swap: " << x << endl;
    cout << "y after swap: " << y << endl;

    return 0;
}
