/*
ID: zhangwf3
PROG: palsquare
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

string show(int n, int b) {
	char digits[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	string s;
	for (; n > 0; n /= b)
		s = digits[n % b] + s;
	return s;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int B;
    const int N = 300;
    fin >> B;
    for (int n = 1; n <= N; ++n)
    	if (palindrome(n*n, B))
    		fout << show(n, B) << ' ' << show(n*n, B) << endl;
    return 0;
}