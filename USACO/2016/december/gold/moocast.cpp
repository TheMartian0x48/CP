/*
 * TheMartian0x48
 * USACO 2016 December Contest, Gold
 * Problem 1. Moocast
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
int nmax = 1005, n;
vector<pair<int, int>> co(nmax);
vector<vi> g(nmax);
vector<bool> used(nmax);

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) 
      if (used[u] == false) dfs(u);
}

bool good(int r) { 
  rep(i,0,n) g[i].clear();
  used.assign(n, false);
  rep(i,0,n) rep(j,i+1,n) {
    ll d = pow(co[i].first - co[j].first, 2) + pow(co[i].second - co[j].second, 2);
    if (d <= r) g[i].push_back(j), g[j].push_back(i); 
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (used[i] == false) {
      c++;
      if (c > 1) return false;
      dfs(i);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("moocast");

  cin >> n;
  rep(i,0,n) cin >> co[i].first >> co[i].second;

  int l = -1, r = 1e9;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (good(m)) r = m;
    else l = m;
  }
  cout << r;
}
