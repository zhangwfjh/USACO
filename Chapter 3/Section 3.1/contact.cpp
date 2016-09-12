/*
ID: zhangwf3
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool patcmp(pair<string, size_t> p, pair<string, size_t> q) {
  return p.second > q.second
      || p.second == q.second && (p.first.length() < q.first.length()
                              ||  p.first.length() == q.first.length() && p.first < q.first);
}

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    size_t A, B, N;
    fin >> A >> B >> N;
    string data = "";
    for (string subdata,i="*"; !fin.eof(); data += subdata, subdata = "") fin >> subdata;

    map<string, size_t> pattern;
    for (size_t i = 0; i < data.length(); ++i)
      for (size_t l = A; l <= B; ++l)
        if (i+l <= data.length())
          ++pattern[data.substr(i, l)];
    vector< pair<string, size_t> > frequency(N);
    for (map<string, size_t>::iterator it = pattern.begin(); it != pattern.end(); ++it) {
      cout << it->second << ' ' << it->first << endl;
      frequency.push_back(*it);
    }
    sort(frequency.begin(), frequency.end(), patcmp);
    size_t cur_freq = 0, n = 0, k = 0;
    for (vector< pair<string, size_t> >::iterator it = frequency.begin(); it != frequency.end(); ++it)
      if (it->second > 0)
        if (it->second == cur_freq)
          if (++k % 6) fout << ' ' << it->first;
          else fout << endl << it->first;
        else if (n++ == N) break;
        else {
          if (cur_freq > 0) fout << endl;
          cur_freq = it->second;
          k = 0;
          fout << cur_freq << endl << it->first;
        }
    fout << endl;
    return 0;
}
