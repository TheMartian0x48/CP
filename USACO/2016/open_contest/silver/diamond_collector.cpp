/*
 * TheMartian0x48 
 * USACO 2016 US Open Contest, Silver
 * Problem 2. Diamond Collector
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
// clang-format on

// ---------------- (* Extract here *)
// ----------------


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n; cin >> n;
  ll k; cin >> k;
  vii v;
  re(v, n);
  sort(all(v));

  vi sets(n);
  for (int i = 0, j = 0; i < sz(v); i++) {
    while(v[i] - v[j] > k) j++;
    sets[i] = i - j + 1;
  }
  vi size(n);
  size[0] = sets[0];
  int mx = 1;
  for (int i = 1; i < n; i++) {
    int id = i - sets[i];
    if (id >= 0) mx = max(mx, size[id] + sets[i]);
    size[i] = max(sets[i], size[i - 1]);
  }
  cout << mx;
}