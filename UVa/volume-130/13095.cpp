/*
 * TheMartian0x48
 * 13095 
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

  int nmax = 1e5 + 5;
  vector<vi> dp(nmax, vi(10));
  int n;
  while (cin >> n) {
    int t;
    rep(i,0,n) {
      cin >> t;
      rep(j,0,10)
        dp[i + 1][j] = dp[i][j];
      dp[i + 1][t]++;
    }
    int q; cin >> q;
    while (q--) {
      int l, r; cin >> l >> r;
      int res = 0;
      rep(i,0,10) {
        res += dp[r][i] > dp[l - 1][i];
      }
      cout << res << "\n";
    }
  }  
}
