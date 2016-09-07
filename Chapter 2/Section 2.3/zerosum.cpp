/*
ID: zhangwf3
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    size_t N;
    fin >> N;
    for (size_t i = 0; i < (unsigned int) pow(3, N-1); ++i) {
      int sum = 0, temp = 1;
      for (size_t j = 0; j < N-1; ++j)
        switch (i / (unsigned int) pow(3, N-2-j) % 3) {  // 0: blank; 1: add; 2: subtraction
          case 0: {
                    int diff = temp - sum;
                    if (abs(diff) >= 10) j = N-1;
                    temp = sum + diff*10 + copysign(j+2, diff);
                    break;
                  }
          case 1: sum = temp; temp += j+2; break;
          case 2: sum = temp; temp -= j+2; break;
        }
      if (temp == 0) {
        fout << 1;
        for (size_t j = 0; j < N-1; ++j) {
          switch (i / (unsigned int) pow(3, N-2-j) % 3) {
            case 0: fout << ' '; break;
            case 1: fout << '+'; break;
            case 2: fout << '-'; break;
          }
          fout << j+2;
        }
        fout << endl;
      }
    }
    return 0;
}
