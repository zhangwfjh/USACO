/*
ID: zhangwf3
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool palindrome(int n, int b) {
	int revn = 0;
	for (int k = n; k > 0; k /= b)
		revn = revn * b + k % b;
	return revn == n;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S, n = 0;
    fin >> N >> S;
    int k = S + 1;
    while (n < N) {
    	int pal = 0;
    	for (int b = 2; b <= 10 && pal < 2; ++b)
    		if (palindrome(k, b)) ++pal;
    	if (pal == 2) {
    		++n;
    		fout << k << endl;
    	}
    	++k;
    }
    return 0;
}