/*
 * TheMartian0x48
 * USACO 2016 December Contest, Silver
 * Problem 3. Moocast
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

int nmax=205;
vector<vector<int>> g(nmax);
vector<bool> used(nmax, false);
stack<int> st;


int dfs(int v) { 
  used[v] = true;
  int c = 1;
  for (auto u : g[v]) {
    if (used[u] == false) c += dfs(u);
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  usaco("moocast");
  int n;
  cin >> n;
  vector<pair<int, int>> cow(n);
  vi r(n);
  rep(i,0,n) cin >> cow[i].first >> cow[i].second >> r[i];
  rep(i,0,n) {
    rep(j,i+1, n) {
      ll d = pow((cow[i].first - cow[j].first) , 2) + pow((cow[i].second - cow[j].second) , 2);
      if ( r[i] * r[i] >= d) g[i].push_back(j);
      if ( r[j] *  r[j] >= d) g[j].push_back(i);
    }
  }
  int res = 0;
  
  for (int i = 0; i < n; i++) {
    used.assign(n, false);
    res = max(res, dfs(i));
  }
  cout << res ;    
}
