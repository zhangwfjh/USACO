/*
ID: zhangwf3
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

size_t binomial(size_t n, size_t k) {
  double b = 1;
  for (size_t i = 0; i < k; ++i)
    b *= (double)(n-i)/(i+1);
  return round(b);
}

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    size_t N, L, I;
    fin >> N >> L >> I;
    for (size_t n = N; n > 0; --n) {
      size_t rest = 0;
      for (size_t l = 0; l <= L && l < n; ++l) rest += binomial(n-1, l);
      if (I > rest) { fout << 1; I -= rest; --L; }
      else fout << 0;
    }
    fout << endl;
    return 0;
}
