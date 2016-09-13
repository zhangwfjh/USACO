/*
ID: zhangwf3
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    size_t N;
    fin >> N;
    size_t rightmost = 1, twominusfive = 0;
    for (size_t n = 2; n <= N; ++n) {
      size_t k = n;
      while (k % 2 == 0) { k /= 2; ++twominusfive; }
      while (k % 5 == 0) { k /= 5; --twominusfive; }
      rightmost = rightmost * k % 10;
    }
    size_t twoendians[] = {6, 2, 4, 8};
    if (twominusfive > 0) rightmost = (rightmost * twoendians[twominusfive % 4]) % 10;
    fout << rightmost << endl;
    return 0;
}
