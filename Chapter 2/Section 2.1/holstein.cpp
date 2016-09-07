/*
ID: zhangwf3
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    size_t V, G;
    fin >> V;
    int vitamin[V];
    for (size_t v = 0; v < V; ++v) fin >> vitamin[v];
    fin >> G;
    int feed[G][V];
    for (size_t g = 0; g < G; ++g)
      for (size_t v = 0; v < V; ++v)
        fin >> feed[g][v];
    int select;
    int amount[V];
    bool checked[1<<G] = { };
    queue<int> yield;
    yield.push(0);
    while (true) {
      select = yield.front();
      yield.pop();
      for (size_t v = 0; v < V; ++v) amount[v] = 0;
      for (size_t g = 0; g < G; ++g)
        if (select & 1 << g)
          for (size_t v = 0; v < V; ++v)
            amount[v] += feed[g][v];
      bool enough = true;
      for (size_t v = 0; v < V; ++v)
        if (amount[v] < vitamin[v]) {
          enough = false;
          break;
        }
      if (enough) break;
      for (size_t g = 0; g < G; ++g)
        if (!(select & 1 << g)) {
          int next = select + (1 << g);
          if (!checked[next]) {
            yield.push(next);
            checked[next] = true;
          }
        }
    }
    vector<int> types;
    for (size_t g = 0; g < G; ++g)
      if (select & 1 << g) types.push_back(g+1);
    fout << types.size() << " ";
    for (size_t i = 0; i < types.size()-1; ++i)
      fout << types[i] << " ";
    fout << types[types.size()-1] << endl;
    return 0;
}
