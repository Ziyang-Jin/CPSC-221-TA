#include <iostream>

using namespace std;

double arrayMax(double arr[], int sz, int start);

int main() {

    double a[10] = {10,5,23,34,5,6,7,18,59,10};
    double b[9] = {31,2,63,24,5,16,7,48,9};
    
    cout << arrayMax(a, 10, 0) << endl;
    cout << arrayMax(b, 9, 0) << endl;
    
return 0;
}

double arrayMax(double arr[], int sz, int start) {
    if (sz == 1)
        return arr[start];
    double m1 = arrayMax(arr, sz/2, start);
    double m2 = arrayMax(arr, sz-sz/2, start+sz/2);
    if (m1 > m2)
        return m1;
    else 
        return m2;
}

