/*
ID: zhangwf3
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    vector<string> primitive;
    for (string s = ""; s != "."; fin >> s)
      if (s.length()) primitive.push_back(s);
    string S = "";
    for (string s = ""; !fin.eof(); fin >> s) S.append(s);

    size_t max = 0;
    bool prefix[S.length()+1] = {};
    prefix[0] = true;
    for (size_t s = 1; s <= S.length(); ++s)
      for (size_t p = 0; p <= primitive.size(); ++p)
        if (primitive[p].length() <= s && prefix[s-primitive[p].length()] && S.substr(s-primitive[p].length(), primitive[p].length()) == primitive[p]) {
          prefix[s] = true;
          if (s > max) max = s;
        }
    fout << max << endl;
    return 0;
}
