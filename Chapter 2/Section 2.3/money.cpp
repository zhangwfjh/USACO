/*
ID: zhangwf3
PROG: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    size_t V, N;
    fin >> V >> N;
    size_t coin[V];
    for (size_t v = 0; v < V; ++v) fin >> coin[v];

    long long count[V+1][N+1] = {};
    for (size_t v = 1; v <= V; ++v) count[v][0] = 1;
    for (size_t v = 1; v <= V; ++v)
      for (size_t n = 1; n <= N; ++n)
        count[v][n] = count[v-1][n] + (coin[v-1] <= n ? count[v][n-coin[v-1]] : 0);
    fout << count[V][N] << endl;
    return 0;
}
