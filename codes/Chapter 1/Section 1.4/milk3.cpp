/*
ID: zhangwf3
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool status[21][21][21] = {false};
int bucket[3];
int full[3];
vector<int> amount;

bool checkstatus() {
	if (status[bucket[0]][bucket[1]][bucket[2]]) return true;
	status[bucket[0]][bucket[1]][bucket[2]] = true;
	return false;
}

int pour(int x, int y, int z = 0) {
	if (z == 0) z = min(bucket[x], full[y] - bucket[y]);
	bucket[x] -= z, bucket[y] += z;
	return z;
}

void solve() {
	static int strategy[6][2] = {{0,1}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}};
	if (checkstatus()) return;
	// cout << "(" << bucket[0] << "," << bucket[1] << "," << bucket[2] << ")" << endl;
	if (bucket[0] == 0) amount.push_back(bucket[2]);
	for (size_t i = 0; i < 6; ++i) {
		int z = pour(strategy[i][0], strategy[i][1]);
		if (z > 0) {
			// cout << x << "->" << y << ":" << z << endl;
			solve();
			pour(strategy[i][1], strategy[i][0], z);
		}
	}
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    fin >> full[0] >> full[1] >> full[2];
    bucket[0] = bucket[1] = 0, bucket[2] = full[2];
    solve();
    sort(amount.begin(), amount.end());
    for (size_t i = 0; i < amount.size() - 1; ++i) fout << amount[i] << " ";
    fout << amount[amount.size() - 1] << endl;
    return 0;
}