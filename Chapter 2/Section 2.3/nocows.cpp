/*
ID: zhangwf3
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    size_t N, K;
    fin >> N >> K;
    size_t pedigree[K+1][N+1] = {};
    pedigree[1][1] = 1;
    for (size_t lh = 1; lh < K; ++lh)
      for (size_t rh = 1; rh <= lh; ++rh)
        for (size_t ln = 1; ln < N; ln += 2)
          for (size_t rn = 1; rn < N-ln; rn += 2) {
            pedigree[lh+1][ln+rn+1] += pedigree[lh][ln] * pedigree[rh][rn] * (lh == rh ? 1 : 2);
            pedigree[lh+1][ln+rn+1] %= 9901;
          }
    fout << pedigree[K][N] % 9901 << endl;
    return 0;
}
