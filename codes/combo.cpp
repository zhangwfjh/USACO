/*
ID: zhangwf3
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Set method
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int N, count = 0;
    vector<int> JKey(3), MKey(3);
    set<vector<int> > keys;
    fin >> N;
    fin >> JKey[0] >> JKey[1] >> JKey[2] >> MKey[0] >> MKey[1] >> MKey[2];
    for (size_t i = 0; i < 125; ++i) {
		vector<int> jkey(3), mkey(3);
		for (size_t j = 0, k = i; j < 3; ++j, k /= 5) {
			jkey[j] = (JKey[j] + N + k % 5 - 3) % N + 1;
			mkey[j] = (MKey[j] + N + k % 5 - 3) % N + 1;
		}
		keys.insert(jkey);
		keys.insert(mkey);
	}
	fout << keys.size() << endl;
    return 0;
}

// Array method
/*
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int N, count = 0, code[2][3];
    fin >> N;
    fin >> code[0][0] >> code[0][1] >> code[0][2] >> code[1][0] >> code[1][1] >> code[1][2];
    bool keys[N][N][N] = {};
    for (size_t p = 0; p < 2; ++p)
	    for (size_t i = 0; i < 125; ++i) {
	    	int key[3];
	        for (size_t j = 0, k = i; j < 3; ++j, k /= 5)
	            key[j] = (code[p][j] + N + k % 5 - 3) % N;
	        if (!keys[key[0]][key[1]][key[2]]) {
	        	keys[key[0]][key[1]][key[2]] = true;
	        	++count;
	        }
	    }
    fout << count << endl;
    return 0;
}
*/