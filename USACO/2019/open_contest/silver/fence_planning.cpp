/*
 * TheMartian0x48
 * USACO 2019 US Open Contest, Silver
 * Problem 3. Fence Planning
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
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);}
// clang-format on
int nmax = 1e5+5, n;
vector<vi> g(nmax);
vector<pii> co(nmax); 
vector<bool> used(nmax, false);
int xl, xr, yu, yb;

void dfs(int v) {
  used[v] = true;
  xl = min(xl, co[v].first);
  xr = max(xr, co[v].first);
  yu = max(yu, co[v].second);
  yb = min(yb, co[v].second);
  for (auto a : g[v]) { if (used[a] == false) dfs(a); 
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  usaco("fenceplan");

  int m; 
  cin >> n >> m;
  rep(i,1,n+1) cin >> co[i].first >> co[i].second;
  int a, b;
  rep(i,0,m) cin >> a >> b, g[a].push_back(b), g[b].push_back(a);

  ll res = LONG_LONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (used[i] == false) {
      xr = 0, xl = 1e9, yu = 0, yb = 1e9;
      dfs(i);
      res = min(res, 2LL * (xr - xl + yu - yb));
    }
  }
  cout << res;
}
