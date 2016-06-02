#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int * x;
int comps; // Global variable as required

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

// implementation of qc
int qc(int n) {
    if(n > 1) {
        int p = randint(0,n-1);
        return n-1 + qc(p) + qc(n-p-1);
    } else
        return 0;
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a])
			swap(x[++m], x[i]);
            comps++;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000
#define REP 100

int main(int argc, char *argv[]) {
        int avg = 0;
        int qc_comps = 0;
        // a big for loop to let it done repeatedly
        for(int i = 0; i < REP; i++) {

	srand(time(0));
        comps = 0;
	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		cout << x[i] << " ";
	}
	cout << endl;
        avg += comps;
        qc_comps += qc(NN);
	delete[] x;

        }
        avg /= REP;
        qc_comps /= REP;
        cout << "Average Comparisons: " << avg << endl;
        cout << "Pseudo Average Comparisons: " << qc_comps << endl;
	return 0;
}

