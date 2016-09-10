/*
ID: zhangwf3
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ofstream fout ("inflate.out");
  ifstream fin ("inflate.in");
  size_t M, N;
  fin >> M >> N;
  size_t point[N], minute[N];
  for (size_t i = 0; i < N; ++i) fin >> point[i] >> minute[i];
  size_t contest[M+1] = {};
  for (size_t m = 1; m <= M; ++m)
    for (size_t i = 0; i < N; ++i)
      contest[m] = max(contest[m], m >= minute[i] ? contest[m-minute[i]] + point[i] : 0);
  fout << contest[M] << endl;
  return 0;
}
