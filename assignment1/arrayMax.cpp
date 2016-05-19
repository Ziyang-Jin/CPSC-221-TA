#include <iostream>

using namespace std;

double arrayMax(double arr[], int sz, int start);

int main() {

    double a[10] = {10.5,5.87,23.12,34.27,5.01,6.35,7.86,18.00,59.84,10.37};
    double b[9] = {31.12,2.35,63.48,24.43,5.66,16.33,7.99,48.64,9.82};
    
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

