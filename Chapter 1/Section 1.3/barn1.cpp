/*
ID: zhangwf3
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C;
    
    fin >> M >> S >> C;
    if (M >= C) {
    	fout << C << endl;
    	return 0;
    }
    int stall[C], diff[C-1];
    for (size_t i = 0; i < C; ++i) fin >> stall[i];
    sort(stall, stall + C);
    for (size_t i = 0; i < C-1; ++i) diff[i] = stall[i+1] - stall[i];
	sort(diff, diff+C-1, greater<int>());
	int length = stall[C-1] - stall[0] + 1;
	for (size_t m = 0; m < M-1; ++m) length -= diff[m] - 1;
    fout << length << endl;
    return 0;
}

// solution with printed board
/*
bool cmpshadow(int* a, int* b) { return *a > *b; }

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C, sum = 0;
    
    fin >> M >> S >> C;
    if (M >= C) {
    	fout << C << endl;
    	return 0;
    }
    int stall[C], diff[C-1];
    int* shadow[C-1];
    for (size_t i = 0; i < C; ++i) fin >> stall[i];
    sort(stall, stall + C);
    for (size_t i = 0; i < C-1; ++i) {
    	diff[i] = stall[i+1] - stall[i];
    	shadow[i] = diff + i;
	}
	sort(shadow, shadow+C-1, cmpshadow);
	for (size_t m = 0; m < M-1; ++m) *shadow[m] = 0;
	int head = stall[0];
	for (size_t i = 1; i < C; ++i)
		if (diff[i-1] == 0) {
			// cout << head << "-" << stall[i-1] << endl;
			sum += stall[i-1] - head + 1;
			head = stall[i];
		}
	sum += stall[C-1] - head + 1;
    fout << sum << endl;
    return 0;
}
*/