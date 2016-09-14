/*
ID: zhangwf3
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<size_t> vec;
typedef vector<vec> mat;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int gcd(int x[], size_t n) {
  int res = 0;
  for (size_t i = 0; i < n; ++i) res = gcd(res, x[i]);
  return res;
}

int det(mat m) {
  return m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
        +m[0][1]*(m[1][2]*m[2][0] - m[1][0]*m[2][2])
        +m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
}

mat replace(mat m, size_t r, vec v) {
  mat rep(3);
  for (size_t i = 0; i < 3; ++i)
    if (i == r-1) rep[i] = v;
    else rep[i] = m[i];
  return rep;
}

int main() {
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
    const size_t N = 3;
    vec goal(N);
    mat mixture(N);
    for (size_t i = 0; i < N; ++i) fin >> goal[i];
    for (size_t i = 0; i < N; ++i) {
      vec v(3);
      for (size_t j = 0; j < N; ++j) fin >> v[j];
      mixture[i] = v;
    }
    int dets[N+1];
    dets[0] = det(mixture);
    for (size_t i = 1; i <= N; ++i) dets[i] = det(replace(mixture, i, goal));
    int d = gcd(dets, 4);
    for (size_t i = 0; i <= N; ++i) {
      dets[i] /= d;
      if (dets[i] >= 100 || dets[i] < 0) {
        fout << "NONE" << endl;
        return 0;
      }
    }
    for (size_t i = 1; i <= N; ++i) fout << dets[i] << ' ';
    fout << dets[0] << endl;
    return 0;
}
