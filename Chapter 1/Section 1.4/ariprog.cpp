/*
ID: zhangwf3
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N, M;
    bool flag = false;
    fin >> N >> M;
    const int size = 2*M*M + 1;
    bool bisquare[size] = {false};
    for (int p = 0; p <= M; ++p)
        for (int q = p; q <= M; ++q)
            bisquare[p*p + q*q] = true;
    for (int b = 1; b < size; ++b)
        for (int a = 0; a + b*(N-1) < size; ++a) {
            int n = 0;
            for (; n < N && bisquare[a + b*n]; ++n) ;
            if (n == N) {
                fout << a << " " << b << endl;
                flag = true;
            }
        }
    if (!flag) fout << "NONE" << endl;
    return 0;
}

/*
typedef pair<int, int> ariprog;

bool cmpariprog(const ariprog& p, const ariprog& q) { return p.second < q.second; }

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N, M;
    vector<ariprog> ariprogs;
    vector<int> bisquare;
    fin >> N >> M;
    for (int p = 0; p <= M; ++p)
    	for (int q = p; q <= M; ++q)
    		bisquare.push_back(p*p + q*q);
    sort(bisquare.begin(), bisquare.end());
    bisquare.erase(unique(bisquare.begin(), bisquare.end()), bisquare.end());

// DFS: timeout

    // for (vector<int>::iterator head = bisquare.begin(); head != bisquare.end(); ++head) 
    // 	for (vector<int>::iterator next = head+1; next != bisquare.end(); ++next) {
    //         int a = *head, n = 2, a_n = *next, b = a_n - a;
    //         for (vector<int>::iterator cur = next+1; cur != bisquare.end(); ++cur)
    //             if (*cur < a_n + b) continue;
    //             else if (*cur == a_n + b)
    //                 if (++n == N) {
    //                     ariprogs.push_back(make_pair(a, b));
    //                     break;
    //                 }
    //                 else a_n = *cur;                       
    //             else if (*cur > a_n + b) break;
    //     }

// DFS with precomputing storage: memory overflow

    // vector<map<int, int> > nexttable(bisquare.size());
    // for (size_t next = 0; next < bisquare.size(); ++next)
    //     for (size_t prev = 0; prev < next; ++prev)
    //         nexttable[prev][bisquare[next] - bisquare[prev]] = next;
    // for (size_t head = 0; head < nexttable.size(); ++head)
    //     for (map<int, int>::iterator next = nexttable[head].begin(); next != nexttable[head].end(); ++next)
    //         for (int n = 2, b = next->first, i_n = next->second; nexttable[i_n].find(b) != nexttable[i_n].end(); i_n = nexttable[i_n][b])
    //             if (++n == N) {
    //                 ariprogs.push_back(make_pair(bisquare[head], b));
    //                 break;
    //             }

    if (ariprogs.empty()) fout << "NONE" << endl;
    else {
        sort(ariprogs.begin(), ariprogs.end(), cmpariprog);
    	for (vector<ariprog>::iterator it = ariprogs.begin(); it != ariprogs.end(); ++it)
    		fout << it->first << " " << it->second << endl;
    }
    return 0;
}
*/