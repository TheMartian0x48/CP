/*
 * TheMartian0x48
 * USACO 2021 February Contest, Silver
 * Problem 3. Just Green Enough
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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> v(n, vi(n));
  vector<vector<pii>> left(n, vector<pii>(n));

  rep(i,0,n) {
    re(v[i]);
  }
  
  for (int i = 0; i < n; i++) {
    pii p{n, n}, q{n, n};
    for (int j = n - 1; j >= 0; j--) {
      if (v[i][j] < 100) {
        p = {j, j};
      } else if (v[i][j] == 100){
        p = {j, p.second};
      }
      left[i][j] = p;
    }
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] < 100) continue;
      int k = i;
      pii p = left[k][j];
      while (k < n && v[k][j] > 100) {
        p.first = min(p.first, left[k][j].first);
        p.second = min(p.second, left[k][j].second);
        res += p.second - p.first;
        k++;
      }
      while (k < n && v[k][j] >= 100) {
        p.second = min(p.second, left[k][j].second);
        res += p.second - j;
        k++;
      }
    }
  }
  cout << res;
}
