/*
ID: zhangwf3
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const size_t L = 10;
bool grid[L][L] = {};
struct move {
  size_t r, c;
  enum direction { N, E, S, W } dir;
  move(size_t r = 0, size_t c = 0, direction dir = N) : r(r), c(c), dir(dir) {}
  bool operator==(const move& m) const { return this->operator^(m) && dir == m.dir; }
  move operator++(int) {
    move temp(r, c, dir);
    switch (dir) {
      case N: if (r > 0 && !grid[r-1][c]) --r; else dir = E; break;
      case E: if (c < L-1 && !grid[r][c+1]) ++c; else dir = S; break;
      case S: if (r < L-1 && !grid[r+1][c]) ++r; else dir = W; break;
      case W: if (c > 0 && !grid[r][c-1]) --c; else dir = N; break;
    }
    return temp;
  }
  bool operator^(const move& m) const { return r == m.r && c == m.c; }
} C, F;

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    for (size_t i = 0; i < L; ++i)
      for (size_t j = 0; j < L; ++j) {
        char c;
        fin >> c;
        switch (c) {
          case '*': grid[i][j] = true; break;
          case 'C': C.r = i; C.c = j; break;
          case 'F': F.r = i; F.c = j; break;
        }
      }

    vector< pair<move, move> > status;
    for (size_t step = 0; ; ++step) {
      if (C ^ F) { fout << step << endl; break; }
      pair<move, move> cur = make_pair(C++, F++);
      if (find(status.begin(), status.end(), cur) != status.end()) { fout << 0 << endl; break; }
      status.push_back(cur);
    }
    return 0;
}
