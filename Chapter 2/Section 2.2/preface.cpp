/*
ID: zhangwf3
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int N;
    fin >> N;
    char letter[8] = "IVXLCDM";
    const int digit[10][3] = { {0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {1, 1, 0}, {0, 1, 0}, {1, 1, 0}, {2, 1, 0}, {3, 1, 0}, {1, 0, 1} };
    int digits[9] = { };

    for (int n = 1; n <= N; ++n)
      for (int k = n, d = 0; k > 0; k /= 10, ++d)
        for (int i = 0; i < 3; ++i)
          digits[2*d + i] += digit[k % 10][i];

    for (int i = 0; i < 7; ++i)
      if (digits[i] > 0)
        fout << letter[i] << ' ' << digits[i] << endl;
    return 0;
}
