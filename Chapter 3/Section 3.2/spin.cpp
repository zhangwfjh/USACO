/*
ID: zhangwf3
PROG: spin
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const size_t tau = 360;

struct wheel {
  vector<bool> wedge;
  wheel(size_t start = 0, size_t extent = 0) {
    wedge = vector<bool>(tau, false);
    if (extent)
      if (start + extent < tau) fill_n(wedge.begin()+start, extent+1, true);
      else { fill_n(wedge.begin(), start+extent-tau+1, true); fill_n(wedge.begin()+start, tau-start, true); }
  }
  wheel& operator^=(const wheel& w) {
    for (size_t i = 0; i < tau; ++i) wedge[i] = wedge[i] & w.wedge[i];
    return *this;
  }
  wheel& operator+=(const wheel& w) {
    for (size_t i = 0; i < tau; ++i) wedge[i] = wedge[i] | w.wedge[i];
    return *this;
  }
  void spin(size_t alpha) { rotate(wedge.rbegin(), wedge.rbegin()+alpha, wedge.rend()); }
  bool isempty() {
    for (vector<bool>::iterator it = wedge.begin(); it != wedge.end(); ++it)
      if (*it == true) return false;
    return true;
  }
};

int main() {
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    const size_t N = 5;
    size_t speed[N], period[N] = {};
    wheel wheels[N];
    for (size_t i = 0; i < N; ++i) {
      size_t W, start, extent;
      fin >> speed[i] >> W;
      for (size_t j = 0; j < W; ++j) {
        fin >> start >> extent;
        wheels[i] += wheel(start, extent);
      }
      while (speed[i] * ++period[i] % tau) ;
    }
    size_t t = 0;
    do {
      wheel align(0, tau);
      for (size_t i = 0; i < N; ++i) {
        align ^= wheels[i];
        wheels[i].spin(speed[i]);
      }
      if (!align.isempty()) break;
    } while (++t < tau);
    if (t < tau) fout << t << endl;
    else fout << "none" << endl;
    return 0;
}
