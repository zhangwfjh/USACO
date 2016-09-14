/*
ID: zhangwf3
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct path {
  size_t source, target, dist;
  path(size_t s, size_t t, size_t l) : source(s), target(t), dist(l) {}
  bool operator<(const path& p) const { return dist > p.dist; }
};

int main() {
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    size_t N, P, C;
    fin >> N >> P >> C;
    vector<size_t> cow(N);
    for (size_t n = 0; n < N; ++n) fin >> cow[n];
    size_t dist[P][P];
    for (size_t i = 0; i < P; ++i)
      for (size_t j = 0; j < P; ++j)
        dist[i][j] = i == j ? 0 : INT_MAX;
    vector< vector<size_t> > neighbor(P);
    for (size_t c = 0; c < C; ++c) {
      size_t s, t, l;
      fin >> s >> t >> l;
      dist[s-1][t-1] = dist[t-1][s-1] = l;
      neighbor[s-1].push_back(t-1);
      neighbor[t-1].push_back(s-1);
    }
    // Dijkstra algorithm
    for (size_t p = 0; p < P; ++p) {
      priority_queue<path> paths;
      paths.push(path(p, p, 0));
      while (!paths.empty()) {
        size_t q = paths.top().target;
        paths.pop();
        for (vector<size_t>::iterator it = neighbor[q].begin(); it != neighbor[q].end(); ++it)
          if (dist[p][q] + dist[q][*it] <= dist[p][*it]) {
            dist[p][*it] = dist[p][q] + dist[q][*it];
            paths.push(path(p, *it, dist[p][*it]));
          }
      }
    }
    // Floyd-Warshall algorithm, timeout

    // for (size_t k = 0; k < P; ++k)
    //   for (size_t i = 0; i < P; ++i)
    //     for (size_t j = 0; j < P; ++j)
    //       dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    for (size_t i = 0; i < P; ++i) {
      for (size_t j = 0; j < P; ++j)  cout << dist[i][j] << ' ';
      cout << endl; }

    vector<size_t> length(P);
    for (size_t p = 0; p < P; ++p)
      for (size_t n = 0; n < N; ++n)
        length[p] += dist[p][cow[n]-1];
    fout << *min_element(length.begin(), length.end()) << endl;
    return 0;
}
