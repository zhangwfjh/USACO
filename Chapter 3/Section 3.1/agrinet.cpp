/*
ID: zhangwf3
PROG: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct fiber {
  size_t source, target;
  size_t cost;
  fiber(size_t s, size_t t, size_t c): source(s), target(t), cost(c) {}
  bool operator<(const fiber& f) const { return cost > f.cost; }
};

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    size_t N;
    fin >> N;
    priority_queue<fiber> fibers;
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j) {
        size_t c;
        fin >> c;
        if (i < j) fibers.push(fiber(i, j, c));
      }
      
    size_t connect[N] = {};
    for (size_t i = 0; i < N; ++i) connect[i] = N;
    size_t cost = 0;
    while (!fibers.empty()) {
      fiber f = fibers.top();
      fibers.pop();
      size_t srccon, tarcon;
      for (srccon = f.source; connect[srccon] < N; srccon = connect[srccon]) ;
      for (tarcon = f.target; connect[tarcon] < N; tarcon = connect[tarcon]) ;
      if (srccon == tarcon) continue;
      connect[tarcon] = srccon;
      cost += f.cost;
    }
    fout << cost << endl;
    return 0;
}
