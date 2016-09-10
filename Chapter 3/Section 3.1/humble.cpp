/*
ID: zhangwf3
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    size_t K, N;
    fin >> K >> N;
    vector<size_t> prime(K);
    for (size_t k = 0; k < K; fin >> prime[k++]) ;
    set<size_t> humble;
    humble.insert(1);
    set<size_t>::iterator it = humble.begin();
    for (size_t n = 0; n < N; ++n, ++it)
      for (size_t k = 0; k < K; ++k) humble.insert(*it * prime[k]);
    fout << *it << endl;
    return 0;
}
