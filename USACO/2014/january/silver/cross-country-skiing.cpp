
/*
 * TheMartian0x48
 * USACO 2014 January Contest, Silver
 * Problem 2. Cross Country Skiing
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

int n, m;
vector<vector<int>> g, w, check;
const vector<int> dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};

void dfs(int r, int c, int d) {
  check[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    int rr = r + dr[i], cc = c + dc[i];
    if (rr >= 0 && rr < n && cc >= 0 && cc < m && check[rr][cc] != 1) {
      int dd = abs(g[r][c] - g[rr][cc]);
      if (dd <= d) dfs(rr, cc, d);
    }
  }
}

bool good(int sr, int sc, int x) {
  for (auto &r : check) r.assign(m, 0);
  dfs(sr, sc, x);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (w[i][j] == 1 && check[i][j] != 1) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("ccski");

  cin >> n >> m;
  g.resize(n);
  w.resize(n);
  check.resize(n);
  int sr = -1, sc = -1;
  for (auto &r : g){
    r.resize(m);
    for (auto &a : r) cin >> a;
  }
  for (int i = 0; i < n; i++) {
    w[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> w[i][j];
      if (w[i][j] == 1) sr = i, sc = j;
    }
  }
  if (sr == -1 && sc == -1) {
    cout << 0;
    return 0;
  }
  int l = -1, r = 1e9;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    
    if(good(sr, sc, mid)) r = mid;
    else l = mid;
  }
  cout << r;
}
