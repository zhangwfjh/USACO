/*
ID: zhangwf3
PROG: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    unsigned long M;
    fin >> M;

    for (unsigned long n = M+1; ; ++n) {
      int digit[10] = {};
      vector<int> num;
      for (unsigned long i = n; i > 0; i /= 10) { ++digit[i % 10]; num.push_back(i % 10); }
      if (digit[0]) continue;
      bool unique = true;
      for (int d = 1; d < 10; ++d)
        if (digit[d] > 1) { unique = false; break; }
      if (!unique) continue;
      digit[num[0]] = 2;
      for (int d = 0; digit[num[d]]--; d = (num.size() + (d - num[d]) % (int) num.size()) % num.size()) // signed will promote to unsigned;
      bool left = false;
      for (int d = 1; d < 10; ++d)
        if (digit[d] == 1) { left = true; break; }
      if (left) continue;
      fout << n << endl;
      break;
    }
    return 0;
}
