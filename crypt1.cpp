/*
ID: zhangwf3
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> digit;

bool proper(int n, int l) {
	int i = 0;
	for (; n > 0; n /= 10, ++i)
		if (find(digit.begin(), digit.end(), n % 10) == digit.end()) return false;
	return i == l;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int N, total = 0;
    fin >> N;
    for (size_t i = 0; i < N; ++i) {
    	int d;
    	fin >> d;
    	digit.push_back(d);
    }
    for (size_t i = 0; i < N*N*N; ++i) {
    	int abc = digit[i / (N*N)] * 100 + digit[(i / N) % N] * 10 + digit[i % N];
    	for (size_t d = 0; d < N; ++d)
    		for (size_t e = 0; e < N; ++e) {
    			int p1 = digit[e] * abc, p2 = digit[d] * abc;
    			if (proper(p1, 3) && proper(p2, 3) && proper(p1 + p2 * 10, 4)) ++total;
    		}
    }
    fout << total << endl;
    return 0;
}