
/*
 * TheMartian0x48
 * USACO 2017 January Contest, Silver
 * Problem 2. Hoof, Paper, Scissors
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("hps");

  int n; cin >> n;
  vi v(n);
  rep(i,0,n) {
    char ch; cin >> ch; if (ch == 'H') v[i] = 0; else if (ch == 'S') v[i] = 1; else v[i] = 2;
  }
  vector<vi> pre(n, vi(3, 0)), suf(n, vi(3, 0));
  rep(i,0,n) {
    if (i) pre[i] = pre[i - 1];
    rep(j,0,3) {
      if ((j + 1) % 3 == v[i]) pre[i][j]++;
      else if (j == (v[i] + 2) % 3) pre[i][j]--;
    }
  }
  per(i,n-1,0) {
    if (i < n - 1) suf[i] = suf[i + 1];
    rep(j,0,3) {
      if ((j + 1) % 3 == v[i]) suf[i][j]++;
      else if (j == (v[i] + 2) % 3) suf[i][j]--;
    }
  }
  int res = max(suf[0][0], max(suf[0][1], suf[0][2]));
  rep(i,0,n - 1) {
    rep(j,0,3) rep(k,0,3) {
      res = max(res, pre[i][j] + suf[i + 1][k]);
    }
  }
  cout << res;
}
