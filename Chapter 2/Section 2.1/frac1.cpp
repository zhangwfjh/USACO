/*
ID: zhangwf3
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

class frac {
public:
    frac(int x, int y) { int d = gcd(x, y); num = x / d; den = y / d; val = (double)x / y; }
    bool operator<(const frac& f) const { return val < f.val; }
    int num, den;
private:
    double val;
    int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
};

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int N;
    fin >> N;
    set<frac> fracs;

    for (size_t i = 1; i < N; ++i)
        for (size_t j = i+1; j <= N; ++j)
            fracs.insert(frac(i,j));
    fout << "0/1" << endl;
    for (set<frac>::iterator it = fracs.begin(); it != fracs.end(); ++it)
        fout << it->num << '/' << it->den << endl;
    fout << "1/1" << endl;

    return 0;
}