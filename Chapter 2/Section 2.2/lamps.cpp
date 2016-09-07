/*
ID: zhangwf3
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    size_t N, C;
    set<size_t> on, off;
    fin >> N >> C;
    for (int i = 0; i != -1; fin >> i)
      if (i > 0) on.insert(i % 6);
    for (int i = 0; i != -1; fin >> i)
      if (i > 0) off.insert(i % 6);
    if (C == 0 && off.size() == 0) {
      for (size_t i = 0; i < N; ++i) fout << 1;
      fout << endl;
      return 0;
    }
    bool config[8][6] = { {0,0,0,0,0,0}, {0,0,1,1,1,0},
                          {0,1,0,1,0,1}, {0,1,1,0,1,1},
                          {1,0,0,1,0,0}, {1,0,1,0,1,0},
                          {1,1,0,0,0,1}, {1,1,1,1,1,1}  };
    size_t step[8] = {1, 2, 1, 1, 2, 1, 2, 2};
    size_t count = 0;
    for (size_t c = 0; c < 8; ++c) {
      bool qualified = true;
      for (set<size_t>::iterator it = on.begin(); it != on.end(); ++it)
        if (!config[c][*it-1]) { qualified = false; break; }
      for (set<size_t>::iterator it = off.begin(); it != off.end(); ++it)
        if (config[c][*it-1]) { qualified = false; break; }
      if (qualified && (C > 2 || C == step[c])) {
        ++count;
        for (size_t i = 0; i < N; ++i) fout << config[c][i%6];
        fout << endl;
      }
    }
    if (!count) fout << "IMPOSSIBLE" << endl;
    return 0;
}
