/*
ID: zhangwf3
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef vector<size_t> config;

const size_t N = 8;

config transform(config conf, size_t type) {
  config c(N);
  switch (type) {
    case 0:
      c[0] = conf[7]; c[1] = conf[6]; c[2] = conf[5]; c[3] = conf[4];
      c[4] = conf[3]; c[5] = conf[2]; c[6] = conf[1]; c[7] = conf[0];
      break;
    case 1:
      c[0] = conf[3]; c[1] = conf[0]; c[2] = conf[1]; c[3] = conf[2];
      c[4] = conf[5]; c[5] = conf[6]; c[6] = conf[7]; c[7] = conf[4];
      break;
    case 2:
      c[0] = conf[0]; c[1] = conf[6]; c[2] = conf[1]; c[3] = conf[3];
      c[4] = conf[4]; c[5] = conf[2]; c[6] = conf[5]; c[7] = conf[7];
      break;
  }
  return c;
}

int main() {
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");
    config init(N), tar(N);
    for (size_t i = 0; i < N; ++i) { init[i] = i+1; fin >> tar[i]; }
    map<config, pair<config, char> > track;
    track[init] = make_pair(init, 'O');
    queue<config> conf;
    conf.push(init);
    while (!conf.empty()) {
      config c = conf.front();
      conf.pop();
      if (c == tar) break;
      for (size_t type = 0; type < 3; ++type) {
        config tc = transform(c, type);
        if (track.find(tc) == track.end()) {
          track[tc] = make_pair(c, (char)('A' + type));
          conf.push(tc);
        }
      }
    }
    vector<char> path;
    size_t step = 0;
    for (config c = tar; track[c].second != 'O'; c = track[c].first, ++step)
      path.push_back(track[c].second);
    fout << step << endl;
    for (vector<char>::reverse_iterator it = path.rbegin(); it != path.rend(); ++it)
      fout << *it;
    fout << endl;
    return 0;
}
