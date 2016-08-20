/*
ID: zhangwf3
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool leapyear(int year) { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int daysinmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap[] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int N;
    int weekday = 6;
    int daysnum[7] = {};

	fin >> N;
    for (int year = 1900; year < 1900 + N; ++year)
    	for (int month = 0; month < 12; ++month) {
    		++daysnum[weekday];
    		weekday = (weekday + daysinmonth[month] + (leapyear(year) ? leap[month] : 0)) % 7;
    	}
    fout << daysnum[6] << " " << daysnum[0] << " " << daysnum[1] << " " << daysnum[2] << " " << daysnum[3] << " " << daysnum[4] << " " << daysnum[5] << endl;

    return 0;
}