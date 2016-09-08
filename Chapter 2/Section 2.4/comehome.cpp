/*
ID: zhangwf3
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

struct pasture {
  size_t num, dist;
  pasture(size_t n, size_t d) : num(n), dist(d) {}
  bool operator<(const pasture& p) { return dist > p.dist; }
};

int main() {
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    size_t P;
    fin >> P;
    map<char, size_t> num;
    const size_t N = 52;
    const size_t barn = N-1;
    for (char c = 'a'; c <= 'z'; ++c) num[c] = c - 'a';
    for (char c = 'A'; c <= 'Z'; ++c) num[c] = 26 + c - 'A';
    size_t path[N][N];
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        path[i][j] = UINT_MAX;
    for (size_t i = 0; i < P; ++i) {
      char a, b;
      size_t d;
      fin >> a >> b >> d;
      if (path[num[a]][num[b]] > d) path[num[a]][num[b]] = path[num[b]][num[a]] = d;
    }

    vector<pasture> pastures;
    for (size_t i = 0; i < barn; ++i) pastures.push_back(pasture(i, path[i][barn]));
    make_heap(pastures.begin(), pastures.end());
    while (!pastures.empty()) {
      pop_heap(pastures.begin(), pastures.end());
      pasture p = pastures.back();
      pastures.pop_back();
      if (p.num >= 26) { fout << (char)('A' + p.num - 26) << ' ' << p.dist << endl; break; }
      for (vector<pasture>::iterator it = pastures.begin(); it != pastures.end(); ++it)
        if (path[p.num][it->num] < UINT_MAX && path[p.num][it->num] + p.dist < it->dist)
          it->dist = path[p.num][it->num] + p.dist;
      make_heap(pastures.begin(), pastures.end());
    }
    return 0;
}
