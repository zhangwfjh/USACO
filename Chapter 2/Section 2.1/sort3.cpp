/*
ID: zhangwf3
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int N;
    fin >> N;
    int num[N];
    int ones = 0, twos = 0;
    for (size_t i = 0; i < N; ++i) {
        fin >> num[i];
        switch (num[i]) {
            case 1: ++ones; break;
            case 2: ++twos; break;
        }
    }

    size_t derange[4][4] = { };
    for (size_t i = 0; i < N; ++i) 
         if (i < ones)      ++derange[1][num[i]];
    else if (i < ones+twos) ++derange[2][num[i]];
    else                    ++derange[3][num[i]];
    size_t swap12 = min(derange[1][2], derange[2][1]),
           swap23 = min(derange[2][3], derange[3][2]),
           swap31 = min(derange[3][1], derange[1][3]);
    size_t rotate = max(derange[1][2], derange[2][1]) - swap12;
    fout << swap12 + swap23 + swap31 + 2*rotate << endl;

    // Greedy algorithm: Wrong
    /*
    size_t swap = 0;
    for (size_t one = 0, two = ones, three = ones + twos; one < ones && (two < ones + twos || three < N) || two < ones + twos && three < N;) {
        for (; num[one] == 1 && one < ones; ++one) ;
        for (; num[two] == 2 && two < ones + twos; ++two) ;
        for (; num[three] == 3 && three < N; ++three) ;
        if (one < ones && two < ones + twos && num[one] == 2 && num[two] == 1) { ++swap; ++one; ++two; }
        else if (two < ones + twos && three < N && num[two] == 3 && num[three] == 2) { ++swap; ++two; ++three; }
        else if  (three < N && one < ones && num[three] == 1 && num[one] == 3) { ++swap; ++three; ++one; }
        else if (one < ones && two < ones + twos && three < N) { swap += 2; ++one; ++two; ++three; }
    }
    fout << swap << endl;
    */

    return 0;
}