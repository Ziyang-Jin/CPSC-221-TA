#include <iostream>
#include "omp.h"

using namespace std;

double arrayMax(double arr[], int sz, int start);

int main() {
    double m;
    double a[10] = {10.5, 5.87, 23.12, 34.27, 5.01, 6.35, 7.86, 18.00, 59.84, 10.37};
    #pragma omp parallel
    #pragma omp single
    { m = arrayMax(a, 10, 0); }
    cout << "The maximum is: " << m << endl;
    
return 0;
}

double arrayMax(double arr[], int sz, int start) {
    if (sz == 1)
        return arr[start];
    double m1, m2;
    #pragma omp task untied shared(m1)
    {  m1 = arrayMax(arr, sz/2, start); }
    m2 = arrayMax(arr, sz-sz/2, start+sz/2);
    #pragma omp taskwait
    return (m1 > m2 ? m1 : m2);
}

