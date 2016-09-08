/*
ID: zhangwf3
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>

using namespace std;

int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");
    stringstream sstr;
    size_t N, D;
    fin >> N >> D;
    sstr << N / D << '.';
    vector<size_t> dec, rem;
    set<size_t> rems;   // shadow for rem, in order to improve speed
    rems.insert(0);
    size_t r = N % D;
    for (; rems.find(r) == rems.end(); r %= D) {
      rem.push_back(r);
      rems.insert(r);
      r *= 10;
      dec.push_back(r / D);
    }
    vector<size_t>::iterator repeat = find(rem.begin(), rem.end(), r);
    if (dec.empty()) sstr << '0';
    else if (r == 0)
      for (vector<size_t>::iterator dit = dec.begin(); dit != dec.end(); ++dit) sstr << *dit;
    else {
      for (vector<size_t>::iterator dit = dec.begin(), rit = rem.begin(); dit != dec.end(); ++dit, ++rit) {
        if (rit == repeat) sstr << '(';
        sstr << *dit;
      }
      sstr << ')';
    }
    string out = sstr.str();
    for (size_t i = 0; i < out.length(); i += 76)
      fout << out.substr(i, 76) << endl;
    return 0;
}
