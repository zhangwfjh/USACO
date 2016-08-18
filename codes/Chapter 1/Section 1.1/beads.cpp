/*
ID: zhangwf3
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;
    int maxlen = 0, prelen = 0, curlen = 0, wlen = 0;
    string necklace;

    fin >> N >> necklace;
    necklace += necklace;

    char color = 'w';
    for (size_t i = 0; i < necklace.size(); i++) {
    	if (color == necklace[i] || color == 'w' || necklace[i] == 'w')
    		++curlen;
    	else {
    		if (prelen + curlen > maxlen) maxlen = prelen + curlen;
    		prelen = curlen - wlen;
    		curlen = wlen + 1;
    	}
    	wlen = necklace[i] == 'w' ? wlen + 1 : 0;
    	if (necklace[i] != 'w') color = necklace[i];
    }
    fout << (maxlen < N && maxlen > 0 ? maxlen : N) << endl;
    return 0;
}