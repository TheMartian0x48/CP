/*
 * TheMartian0x48 
 * USACO 2019 February Contest, Silver
 * Problem 2. Painting the Barn
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

  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);

  vector<vi> v(1005, vi(1005, 0));
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    v[y1][x1]++;
    v[y2][x2]++;
    v[y1][x2]--;
    v[y2][x1]--;    
  }
  int res = 0;
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (j - 1 >= 0) v[i][j] += v[i][j - 1];
      if (i - 1 >= 0) v[i][j] += v[i - 1][j];
      if (i - 1 >= 0 && j - 1 >= 0) v[i][j] -= v[i - 1][j - 1];
      res += v[i][j] == k;
    }
  }
  cout << res;
}