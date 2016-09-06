/*
ID: zhangwf3
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    size_t N, B, D;
    fin >> N >> B >> D;

    size_t codewords[N] = {0};
    for (size_t i = 1, n = 1; i < 1<<B && n < N; ++i) {
      bool next = true;
      for (size_t k = 0; k < n; ++k) {
        int d = i ^ codewords[k];
        for (size_t j = 0; j < D-1; ++j) d &= d-1;
        if (!d) {
          next = false;
          break;
        }
      }
      if (next) codewords[n++] = i;
    }

    for (size_t n = 0; n < N-1; ++n) {
      fout << codewords[n];
      if (n % 10 == 9) fout << endl; else fout << " ";
    }
    fout << codewords[N-1] << endl;
    return 0;
}
