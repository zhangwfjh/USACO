/*
ID: zhangwf3
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    size_t K, N;
    fin >> K >> N;
    vector<size_t> stamp(N);
    for (size_t n = 0; n < N; ++n) fin >> stamp[n];
    const size_t T = 10000;
    vector<size_t> value(T+1);
    for (size_t x = 1; ; ++x) {
      size_t i = T + x%T;
      value.push_back(K+1);
      for (size_t n = 0; n < N; ++n)
        if (x >= stamp[n]) value[i] = min(value[i], value[i-stamp[n]]+1);
      if (value[i] == K+1) { fout << x-1 << endl; break; }
      if (value.size() == 2*T) value.erase(value.begin(), value.begin()+T);
    }
    // Brute force, timeout
    /*
    set<size_t> value;
    value.insert(0);
    for (size_t k = 0; k < K; ++k) {
      set<size_t> newvalue;
      for (size_t n = 0; n < N; ++n)
        for (set<size_t>::iterator it = value.begin(); it != value.end(); ++it) newvalue.insert(*it + stamp[n]);
      value.insert(newvalue.begin(), newvalue.end());
    }
    size_t i = 0;
    for (set<size_t>::iterator it = value.begin(); it != value.end() && *it == i; ++it, ++i) ;
    fout << i-1 << endl;
    */
    return 0;
}
