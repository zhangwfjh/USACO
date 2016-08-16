/*
ID: zhangwf3
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    vector<string> names;
    size_t NP;
    map<string, int> balance;

    fin >> NP;
    for (size_t np = 0; np < NP; ++np) {
    	string name;
    	fin >> name;
    	names.push_back(name);
    	balance[name] = 0;
    }
    for (size_t np = 0; np < NP; ++np) {
    	string giver;
    	int money, num;
    	fin >> giver >> money >> num;
    	if (num == 0) continue;
    	balance[giver] -= money - money % num;
    	for (size_t i = 0; i < num; ++i) {
    		string receiver;
    		fin >> receiver;
    		balance[receiver] += money / num;
    	}
    }
    for (vector<string>::const_iterator it = names.begin(); it != names.end(); ++it)
    	fout << *it << " " << balance[*it] << endl;
    return 0;
}