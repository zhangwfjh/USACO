/*
ID: zhangwf3
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdic ("dict.txt");

    string num;
    vector<string> hitted;
    map<char, int> dict;
    dict['A'] = dict['B'] = dict['C'] = 2;
	dict['D'] = dict['E'] = dict['F'] = 3;
	dict['G'] = dict['H'] = dict['I'] = 4;
	dict['J'] = dict['K'] = dict['L'] = 5;
	dict['M'] = dict['N'] = dict['O'] = 6;
	dict['P'] = dict['R'] = dict['S'] = 7;
	dict['T'] = dict['U'] = dict['V'] = 8;
	dict['W'] = dict['X'] = dict['Y'] = 9;

	fin >> num;
	int length = num.length();
    while (!fdic.eof()) { 
    	string name;
    	fdic >> name;
    	if (name.length() == length) {
    		bool match = true;
    		for (int i = length-1; i >= 0; --i)
    			if (dict[name[i]] != num[i] - '0') {
    				match = false;
    				break;
    			}
    		if (match) hitted.push_back(name);
    	}
    }

    if (hitted.empty()) 
    	fout << "NONE" << endl;
    else
    	for (vector<string>::const_iterator it = hitted.begin(); it != hitted.end(); ++it)
    		fout << *it << endl;

    return 0;
}

// time-out method
/*
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fdic ("dict.txt");
    vector<int> num;
    char keypad[10][3] = {	{}, {}, 		 {'A', 'B', 'C'}, {'D', 'E', 'F'}, 
    						{'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'},
    						{'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}	};
    vector<string> dict, hitted;

    while (!fin.eof()) {
    	char c;
    	fin >> c;
    	num.push_back(c - '0');
    }
    while (!fdic.eof()) {
    	string word;
    	fdic >> word;
    	dict.push_back(word);
    }
    size_t size = num.size() - 1;

    int n = pow(3, size);
    for (size_t i = 0; i < n; ++i) {
    	string name = "";
    	for (size_t j = 0, k = i; j < size; ++j, k /= 3)
    		name = keypad[num[size-1-j]][k % 3] + name;
    	if (find(dict.begin(), dict.end(), name) != dict.end()) hitted.push_back(name);
    }
    if (hitted.empty()) 
    	fout << "NONE" << endl;
    else
    	for (vector<string>::const_iterator it = hitted.begin(); it != hitted.end(); ++it)
    		fout << *it << endl;

    return 0;
}
*/

