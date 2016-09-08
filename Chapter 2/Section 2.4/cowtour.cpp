/*
ID: zhangwf3
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

bool isposfin(double x) { return x > 0 && x < DBL_MAX; }
double hypot(double x, double y) { return sqrt(x*x + y*y); }

int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
    size_t N;
    fin >> N;
    double x[N], y[N];
    for (size_t i = 0; i < N; ++i) fin >> x[i] >> y[i];
    double farm[N][N], dist[N][N];
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j) {
        char connected;
        fin >> connected;
        farm[i][j] = connected == '1' ? hypot(x[i]-x[j], y[i]-y[j]) : 0;
      }
    // set initial weight
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        dist[i][j] = i == j ? 0 : farm[i][j] ? farm[i][j] : DBL_MAX;
    // finds shortest path between all pairs of points by Floyd algorithm
    for (size_t k = 0; k < N; ++k)
      for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
          if (dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];
    // finds field number
    size_t pasture[N] = {};
    size_t field = 0;
    for (size_t i = 0; i < N; ++i)
      if (!pasture[i]) {
        pasture[i] = ++field;
        for (size_t j = 0; j < N; ++j)
          if (isposfin(dist[i][j])) pasture[j] = field;
      }
    // computes field diameter
    double fielddiam[field] = {};
      for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
          if (pasture[i] == pasture[j] && dist[i][j] > fielddiam[pasture[i]-1])
            fielddiam[pasture[i]-1] = dist[i][j];
    // computes connected field diameter and compares
    double connecteddiam = DBL_MAX;
    for (size_t i = 0; i < N; ++i)
      for (size_t j = 0; j < N; ++j)
        if (!isposfin(dist[i][j]) && i != j) {
          double diam = hypot(x[i]-x[j], y[i]-y[j]);
          double diami = 0, diamj = 0;
          for (size_t k = 0; k < N; ++k) {
            if (isposfin(dist[i][k]) && dist[i][k] > diami) diami = dist[i][k];
            if (isposfin(dist[j][k]) && dist[j][k] > diamj) diamj = dist[j][k];
          }
          diam += diami + diamj;
          connecteddiam = min(connecteddiam, max(diam, max(fielddiam[pasture[i]-1], fielddiam[pasture[j]-1])));
        }
    fout.precision(6);
    fout << fixed << connecteddiam << endl;
    return 0;
}
