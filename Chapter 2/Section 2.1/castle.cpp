/*
ID: zhangwf3
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int M, N;
    fin >> M >> N;
    int wall[N][M], num[N][M];
    vector<size_t> sizes;
    size_t total = 0;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j) {
            fin >> wall[i][j];
            num[i][j] = -1;
        }

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j)
            if (num[i][j] == -1) {
                sizes.push_back(0);
                queue< pair<int, int> > rooms;
                rooms.push(make_pair(i,j));
                while (!rooms.empty()) {
                    pair<int, int> room = rooms.front();
                    rooms.pop();
                    if (num[room.first][room.second] > -1) continue;
                    else num[room.first][room.second] = total;
                    ++sizes[total];
                    // west, north, east, south = 1, 2, 4, 8
                    if (!(wall[room.first][room.second] & 1) && room.second > 0) rooms.push(make_pair(room.first, room.second-1));
                    if (!(wall[room.first][room.second] & 2) && room.first > 0) rooms.push(make_pair(room.first-1, room.second));
                    if (!(wall[room.first][room.second] & 4) && room.second < M-1) rooms.push(make_pair(room.first, room.second+1));
                    if (!(wall[room.first][room.second] & 8) && room.first < N-1) rooms.push(make_pair(room.first+1, room.second));
                }
                ++total;
            }
    fout << total << endl << *max_element(sizes.begin(), sizes.end()) << endl;

    size_t maxsize = 0, maxi, maxj;
    char dir; 
    for (size_t j = 0; j < M; ++j)
        for (int i = N-1; i >= 0; --i) {
            if (i > 0 && num[i][j] != num[i-1][j] && sizes[num[i][j]]+sizes[num[i-1][j]] > maxsize) {
                maxsize = sizes[num[i][j]] + sizes[num[i-1][j]];
                maxi = i, maxj = j;
                dir = 'N';
            }
            if (j < M-1 && num[i][j] != num[i][j+1] && sizes[num[i][j]]+sizes[num[i][j+1]] > maxsize) {
                maxsize = sizes[num[i][j]] + sizes[num[i][j+1]];
                maxi = i, maxj = j;
                dir = 'E';
            }
        }
    fout << maxsize << endl << maxi+1 << ' ' << maxj+1 << ' ' << dir << endl;
    
    return 0;
}