/*
ID: zhangwf3
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int R;
    fin >> R;
    int tri[R][R] = {}, sum[R][R] = {};
    for (size_t i = 0; i < R; ++i)
    	for (size_t j = 0; j <= i; ++j)
    		fin >> tri[i][j];
    sum[0][0] = tri[0][0];
    for (size_t i = 1; i < R; ++i) {
    	sum[i][0] = sum[i-1][0] + tri[i][0];
    	sum[i][i] = sum[i-1][i-1] + tri[i][i];
    }
    for (size_t i = 1; i < R; ++i)
    	for (size_t j = 1; j < i; ++j)
    		sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + tri[i][j];
    int M = 0;
    for (size_t j = 0; j < R; ++j) {
    	M = max(M, sum[R-1][j]);
    	cout << sum[R-1][j] << endl;
    }
    fout << M << endl;
    return 0;
}