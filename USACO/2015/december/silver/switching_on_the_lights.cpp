
/*
 * TheMartian0x48
 * USACO 2015 December Contest, Silver
 * Problem 1. Switching on the Lights
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
int n, nmax = 100;
vector<vector<vector<pii>>> g(105, vector<vector<pii>>(105));
vector<vi> v(105, vi(105, 0));
vi dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};
bool valid(int r, int c) {
  if ( r < 0 || c < 0 || r >= n || c >= n) return false;
  return true;
}

int dfs(int r, int c) {
  if (!valid(r, c) || v[r][c] != 1) return 0;
  v[r][c] = -1;
  int res = 0;
  vector<pii> tmp;
  for (auto a : g[r][c]) {
    if (v[a.first][a.second] == 0) {
      v[a.first][a.second] = 1, res++;
      bool flag = false;
      for (int i = 0; i < 4; i++) {
        int rr = a.first + dr[i];
        int cc = a.second + dc[i];
        if (valid(rr, cc) && v[rr][cc] == -1) {
          flag = true;
        }
      }
      if (flag) tmp.push_back({a.first, a.second});
    }
  }
  for (int i = 0; i < 4; i++) 
    res +=  dfs(r + dr[i], c + dc[i]);
  for (auto a : tmp) 
    res += dfs(a.first, a.second);
  return res;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  usaco("lightson");
  cin >> n;
  int m; cin >> m;
  v[0][0] = 1;
  int res = 1;
  rep(i,0,m) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    g[a][b].push_back({c, d});
  }
  res += dfs(0, 0);
  cout << res;
}
