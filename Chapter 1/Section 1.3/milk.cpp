/*
ID: zhangwf3
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class supplier {
public:
	int price;
	int amount;
	supplier(int p, int a) : price(p), amount(a) {}
	int buy(int num) const { return num * price; }
	int buyall() const { return buy(amount); }
	bool operator<(const supplier& s) { return price < s.price; }
};

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int N, M;
    vector<supplier> sup;
    int cost = 0;

    fin >> N >> M;
    for (size_t i = 0; i < M; ++i) {
    	int p, a;
    	fin >> p >> a;
    	sup.push_back(supplier(p, a));
    }
    sort(sup.begin(), sup.end());
    for (vector<supplier>::iterator it = sup.begin(); it != sup.end(); ++it)
    	if (it->amount <= N) {
    		cost += it->buyall();
    		N -= it->amount;
    	}
    	else {
    		cost += it->buy(N);
    		break;
    	}
    fout << cost << endl;
    return 0;
}