/*
 * TheMartian0x48
 * USACO 2014 March Contest, Silver
 * Problem 2. The Lazy Cow
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

  usaco("lazy");

  int n; cin >> n;
  int k; cin >> k;
  vector<vector<int>> v(n, vector<int>(n));
  for (auto & r : v) {
    for (auto &c : r) {
      cin >> c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      v[i][j] += v[i][j - 1];
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll tmp = 0;

      int t = max(0, i - k);
      int b = min(n - 1, i + k);
      tmp += t > 0 ? v[j][b] - v[j][t - 1] : v[j][b];
      for (int c = max(0, j - k); c < j; c++) {
        int d = k - j + c;
        t = max(0, i - d);
        b = min(n - 1, i + d);
        tmp += t > 0 ? v[c][b] - v[c][t - 1] : v[c][b];
      }
      for (int c = min(n - 1, j + k); c > j; c--) {
        int d = k - c + j;
        t = max(0, i - d);
        b = min(n - 1, i + d);
        tmp += t > 0 ? v[c][b] - v[c][t - 1] : v[c][b];
      }
      res = max(res, tmp);
    }
  }
  cout << res;
}
