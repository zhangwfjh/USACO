/*
ID: zhangwf3
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    const size_t N = 100;
    size_t n;
    fin >> n;
    size_t share[N+1][N+1] = {};
    for (size_t k = 0; k < n; ++k) {
      size_t i, j, p;
      fin >> i >> j >> p;
      share[i][j] = p;
    }

    for (size_t owner = 1; owner <= N; ++owner) {
      queue<size_t> company;
      bool own[N+1] = {};
      company.push(owner);
      own[owner] = true;
      while (!company.empty()) {
        size_t i = company.front();
        company.pop();
        for (size_t j = 1; j <= N; ++j)
          if (!own[j]) {
            if (i != owner) share[owner][j] += share[i][j];
            if (share[owner][j] > 50) {
              company.push(j);
              own[j] = true;
            }
          }
      }
    }

    for (size_t i = 1; i <= N; ++i)
      for (size_t j = 1; j <= N; ++j)
        if (i != j && share[i][j] > 50) fout << i << ' ' << j << endl;
    return 0;
}
