/*
ID: zhangwf3
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int N;
    fin >> N;

	// Dynamic programming on both S and N
    if (N % 4 == 1 || N % 4 == 2) { fout << 0 << endl; return 0; }
    int S = N * (N+1) / 4;
    unsigned long count[N+1][S+1] = {};
    count[0][0] = 1;
    for (size_t n = 1; n <= N; ++n)
    	for (size_t s = 0; s <= S; ++s) {
			count[n][s] = count[n-1][s];
    		if (s >= n)	count[n][s] += count[n-1][s-n];
		}
    fout << count[N][S]/2 << endl;

    return 0;
}

    // Brute force: timeout
	/*
    for (size_t n = 1; n < 1 << N-1; ++n) {
    	long sum = 0;
    	for (size_t d = 0; d < N; ++d)
    		if (n & 1 << d)
	    		sum +=  d + 1;
    	if (sum == S) ++count;
    }
	*/

	// Brute force 2 with dynamic programming on P(N) only: memory overflow
    /*
    long S = N * (N+1) / 4;
    int sum[1 << N-1] = {0};
    queue<long> subset;
    subset.push(0);
    while (!subset.empty()) {
    	long set = subset.front();
    	subset.pop();
    	for (size_t i = 0; i < N; ++i)
    		if (set & 1 << i) {
    			if (sum[set] == -1) {
	    			sum[set] = sum[set - (1 << i)] + i + 1;
	    			if (sum[set] == S) ++count;
	    		}
	    	}
    		else if (set + (1 << i) < 1 << N-1 && !sum[set + (1 << i)]) {
    			subset.push(set + (1 << i));
    			sum[set + (1 << i)] = -1;
    		}
    }
	*/
