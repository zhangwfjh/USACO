/*
ID: zhangwf3
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

size_t N, count = 0;
vector<size_t> tunnels;
vector<pair<int, int> > wormhole;

size_t moveright(const size_t h) {
	size_t next = N;
	for (size_t i = 0; i < N; ++i)
		if (wormhole[i].first > wormhole[h].first && wormhole[i].second == wormhole[h].second)
			if (next == N || wormhole[i].first < wormhole[next].first)
				next = i;
	return next;
}

void checkcycle() {
	for (size_t i = 0; i < N; ++i) {
		bool pass[N] = {};
		for (size_t j = i; j < N; j = moveright(tunnels[j]))
			if (pass[j]) {
				++count;
				return;
			}
			else
				pass[j] = true;
	}
}

void solvefrom(const size_t from) {
	for (size_t to = from + 1; to < N; ++to)
		if (tunnels[to] == N) {
			tunnels[from] = to, tunnels[to] = from;
			size_t next = from + 1;
			for(; next < N; ++next)
				if (tunnels[next] == N) {
					solvefrom(next);
					break;
				}
			if (next == N) checkcycle();
			tunnels[from] = tunnels[to] = N;
		}
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin >> N;
    for (size_t i = 0; i < N; ++i) {
    	int x, y;
    	fin >> x >> y;
    	wormhole.push_back(make_pair(x, y));
    }
    tunnels = vector<size_t>(N, N);
    solvefrom(0);
    fout << count << endl;
    return 0;
}