/*
ID: zhangwf3
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define sq(x) (x)*(x)

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int N, cost = INT_MAX;
    fin >> N;
    vector<int> hill(N);
    for (size_t i = 0; i < N; ++i) fin >> hill[i];
    sort(hill.begin(), hill.end());
	for (size_t h = 0; h <= 100; ++h) {
		int Xsq = 0;
		for (vector<int>::const_iterator it = hill.begin(); it != hill.end(); ++it)
			if (*it < h) Xsq += sq(h - *it);
			else if (*it > h + 17) Xsq += sq(*it - (h + 17));
		if (Xsq < cost) cost = Xsq;
	}
	fout << cost << endl;
    return 0;
}