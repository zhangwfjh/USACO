/*
ID: zhangwf3
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    size_t K, N;
    fin >> K >> N;
    vector<size_t> prime(K);
    vector<size_t> humind(K);
    for (size_t k = 0; k < K; fin >> prime[k++]) ;
    vector<size_t> humble;
    humble.push_back(1);
    for (size_t n = 0, last = 1; n < N; ++n) {
      size_t next = UINT_MAX;
      for (size_t k = 0; k < K; ++k)
        for (size_t i = humind[k]; i <= n; ++i) {
          size_t later = humble[i] * prime[k];
          if (later > last) {
            humind[k] = i;
            if (later < next) next = later;
            break;
          }
        }
      humble.push_back(next);
      last = next;
    }
    fout << humble[N] << endl;
    // timeout
    /*
    set<size_t> humble;
    set<size_t>::iterator it = humble.begin();
    for (size_t n = 0; n < N; ++n, ++it)
      for (size_t k = 0; k < K; ++k) humble.insert(*it * prime[k]);
    fout << *it << endl;
    */
    return 0;
}
