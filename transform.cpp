/*
ID: zhangwf3
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef char* vector;
typedef char** matrix;

int N;

bool matcmp(matrix m, matrix n) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            if (m[i][j] != n[i][j]) return false;
    return true;
}

const matrix rot90(const matrix m) {
	matrix M = new vector[N];
	for (size_t i = 0; i < N; ++i) {
        M[i] = new char[N];
		for (size_t j = 0; j < N; ++j)
			M[i][j] = m[j][N-1-i];
    }
    return M;
}

const matrix rot180(const matrix m) { return rot90(rot90(m)); }

const matrix rot270(const matrix m) { return rot90(rot180(m)); }

const matrix reflect(const matrix m) {
    matrix M = new vector[N];
    for (size_t i = 0; i < N; ++i) {
        M[i] = new char[N];
        for (size_t j = 0; j < N; ++j)
            M[i][j] = m[i][N-1-j];
    }
    return M;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> N;
    matrix oldsq = new vector[N], newsq = new vector[N];
    for (size_t i = 0; i < N; ++i) {
        oldsq[i] = new char[N];
    	for (size_t j = 0; j < N; ++j)
    		fin >> oldsq[i][j];
    }
    for (size_t i = 0; i < N; ++i) {
        newsq[i] = new char[N];
    	for (size_t j = 0; j < N; ++j)
    		fin >> newsq[i][j];
    }

    if (matcmp(rot90(oldsq), newsq)) fout << 1 << endl;
    else if (matcmp(rot180(oldsq), newsq)) fout << 2 << endl;
    else if (matcmp(rot270(oldsq), newsq)) fout << 3 << endl;
    else if (matcmp(reflect(oldsq), newsq)) fout << 4 << endl;
    else if (matcmp(rot90(reflect(oldsq)), newsq) || matcmp(rot180(reflect(oldsq)), newsq) || matcmp(rot270(reflect(oldsq)), newsq)) fout << 5 << endl;
    else if (matcmp(oldsq, newsq)) fout << 6 << endl;
    else fout << 7 << endl;

    return 0;
}