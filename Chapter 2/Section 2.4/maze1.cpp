/*
ID: zhangwf3
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct point {
  size_t row, col, depth;
  point(size_t r = 0, size_t c = 0, size_t d = 0): row(r), col(c), depth(d) {}
};

int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    size_t W, H;
    fin >> W >> H;
    bool maze[2*H+1][2*W+1] = {};
    point exits[2];
    for (size_t i = 0, e = 0; i < 2*H+1; ++i) {
      char c;
      fin >> noskipws >> c;
      for (size_t j = 0; j < 2*W+1; ++j) {
        fin >> noskipws >> c;
        if (c != ' ') maze[i][j] = true;
        else if (i == 0) exits[e++] = point(0, (j+1)/2);
        else if (i == 2*H) exits[e++] = point(H+1, (j+1)/2);
        else if (j == 0) exits[e++] = point((i+1)/2, 0);
        else if (j == 2*W) exits[e++] = point((i+1)/2, W+1);
      }
    }
    size_t depth[H+1][W+1];
    for (size_t i = 1; i <= H; ++i)
      for (size_t j = 1; j <= W; ++j)
        depth[i][j] = UINT_MAX;
    for (size_t k = 0; k < 2; ++k) {
      queue<point> path;
      bool checked[H+1][W+2] = {};
      path.push(exits[k]);
      while (!path.empty()) {
        point p = path.front();
        path.pop();
        for (int dr = -1; dr <= 1; ++dr)
          for (int dc = -1; dc <= 1; ++dc)
            if (abs(dr + dc) == 1) {
              int nrow = p.row + dr;
              int ncol = p.col + dc;
              size_t ndepth = p.depth + 1;
              if (nrow > 0 && nrow <= H && ncol > 0 && ncol <= W    // check boundary
              &&  !maze[p.row*2-1 + dr][p.col*2-1 + dc]             // check obstacle
              &&  !(checked[nrow][ncol]++)                          // check visited
              &&  ndepth < depth[nrow][ncol]) {                     // check depth
                path.push(point(nrow, ncol, ndepth));
                depth[nrow][ncol] = ndepth;
              }
            }
      }
    }

    size_t maxstep = 0;
    for (size_t i = 1; i <= H; ++i)
      for (size_t j = 1; j <= W; ++j)
        if (depth[i][j] > maxstep) maxstep = depth[i][j];
    fout << maxstep << endl;
    return 0;
}
