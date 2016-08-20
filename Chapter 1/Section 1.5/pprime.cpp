/*
ID: zhangwf3
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ofstream fout ("pprime.out");
ifstream fin ("pprime.in");
int a, b;

int length(int n) { return ceil(log(n) / log(10)); }

void printprime(const int* digit, const int l) {
	int n = 0;
	for (size_t i = 0; i < l; ++i)
		n = n*10 + digit[i];
	if (n < a || n > b) return;
	for (int k = 2; k <= sqrt(n); ++k)
		if (n % k == 0) return;
	fout << n << endl;
}

void filldigit(int* digit, const int l, const int k) {
	for (size_t i = 0; i <= 9; ++i) {
		digit[k] = digit[l-k-1] = i;
		if (k == (l-1) >> 1)
			printprime(digit, l);
		else
			filldigit(digit, l, k+1);
	}
}

int main() {
    fin >> a >> b;
    for (int l = length(a); l <= length(b); ++l) {
    	int digit[l];
    	filldigit(digit, l, 0);
    }
    return 0;
}