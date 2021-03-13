/*
 * TheMartian0x48 
 * USACO 2016 February Contest, Silver
 * Problem 3. Milk Pails
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on
int X, Y;
vector<vector<vector<bool>>> vis(205, vector<vector<bool>>(205, vector<bool>(205, false)));
vector<bool> v(205, false);
void solve(int x, int y, int k) {
  if (x > X || y > Y || vis[x][y][k]) return;
  if (k <= 0) {
    vis[x][y][k] = true;
    v[x + y] = true;
    return;
  }
  vis[x][y][k] = true;
  v[x + y] = true;
  // fill 
  if (x < X) solve(X, y, k - 1);
  if (y < Y) solve(x, Y, k - 1);

  // empty
  if (x) solve(0, y, k - 1);
  if (y) solve(x, 0, k - 1);

  // fill other
  int d = min(X - x, y);
  if (d) solve(x + d, y - d, k - 1);
  d = min(x, Y - y);
  if (d) solve(x - d, y + d, k - 1);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int k, m, res = m; 
  cin >> X >> Y >> k >> m;
  solve(0, 0, k);
  for (int i = 0; i < 205; i++) {
    if (v[i] && abs(i - m) < res) res = abs(i - m);
  }
  cout << res;
}
