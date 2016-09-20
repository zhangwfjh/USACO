/*
ID: zhangwf3
PROG: fence
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

int main() {
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    size_t F;
    fin >> F;
    map< size_t, multiset<size_t> > fence;
    map<size_t, size_t> degree;
    for (size_t f = 0; f < F; ++f) {
      size_t i, j;
      fin >> i >> j;
      fence[i].insert(j), fence[j].insert(i);
      ++degree[i], ++degree[j];
    }
    size_t start;
    map<size_t, size_t>::iterator it = degree.begin();
    for (; it != degree.end(); ++it)
      if (it->second % 2) { start = it->first; break; }
    if (it == degree.end()) start = degree.begin()->first;
    stack<size_t> traverse, tour;
    traverse.push(start);
    while (!traverse.empty()) {
      size_t i = traverse.top();
      if (fence[i].empty()) {
        tour.push(i);
        traverse.pop();
      }
      else {
        size_t j = *fence[i].begin();
        traverse.push(j);
        fence[j].erase(fence[j].find(i));
        fence[i].erase(fence[i].find(j));
      }
    }
    for (; !tour.empty(); tour.pop()) fout << tour.top() << endl;
    return 0;
}
