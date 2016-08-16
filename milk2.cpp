/*
ID: zhangwf3
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class interval {
public:
	int start;
	int end;
	interval(int s = 0, int e = 0) : start(s), end(e) {}
	bool disjoint(interval& t) const { return start < t.start && end < t.start || start > t.start && start > t.end; }
	void intunion(const interval& t) { start = min(start, t.start); end = max(end, t.end); }
	int length() const { return end - start; }
	friend bool operator<(const interval& s, const interval& t) { return s.start > t.start; }
};

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N, maxcont = 0, maxidle = 0;
    fin >> N;

    vector<interval> intervals, unions;
    for (size_t i = 0; i < N; i++) {
    	int s, e;
    	fin >> s >> e;
    	intervals.push_back(interval(s, e));
    }
    sort(intervals.begin(), intervals.end());
    while (true) {
    	interval s = intervals.back();
    	intervals.pop_back();
		if (s.length() > maxcont) maxcont = s.length();
    	if (intervals.empty()) break;
    	interval& t = intervals.back();
    	if (t.disjoint(s)) {
    		if (t.start - s.end > maxidle) maxidle = t.start - s.end;
    	}
    	else
    		t.intunion(s);
    }
    fout << maxcont << " " << maxidle << endl;

    return 0;
}