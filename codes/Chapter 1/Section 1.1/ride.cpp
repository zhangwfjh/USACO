/*
ID: zhangwf3
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int number(string str) {
	int prod = 1;
	for (size_t i = 0; i < str.size(); prod *= str[i++] - 'A' + 1) ;
	return prod % 47;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;

    fin >> comet >> group;
    fout << (number(comet) == number(group) ? "GO" : "STAY") << endl;
    return 0;
}