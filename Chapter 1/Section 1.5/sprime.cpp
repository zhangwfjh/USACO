/*
ID: zhangwf3
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int N;
int enddigit[4] = {1, 3, 7, 9};
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

int number(const int *digits) {
	int n = 0;
	for (size_t i = 0; i < N; ++i)
		n = n*10 + digits[i];
	return n;
}

bool prime(const int n) {
	for (int k = 2; k <= sqrt(n); ++k)
		if (n % k == 0) return false;
	return true;
}

void printsprime(int *digits) {
	int n = number(digits);
	for (int k = n; k > 10; k /= 10)
		if (!prime(k)) return;
	fout << n << endl;
}

void filldigits(int* digits, const int i) {
	if (i == N) printsprime(digits);
	else
		for (size_t k = 0; k < 4; ++k) {
			digits[i] = enddigit[k];
			filldigits(digits, i+1);
		}
}

int main() {
    fin >> N;
    int primedigit[4] = {2, 3, 5, 7};
    if (N == 1) 
    	for (size_t i = 0; i < 4; ++i)
    		fout << primedigit[i] << endl;
    else {
    	int digits[N] = { };
    	for (size_t i = 0; i < 4; ++i) {
    		digits[0] = primedigit[i];
    		filldigits(digits, 1);
    	}
    }
    return 0;
}