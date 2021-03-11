/*
 * TheMartian0x48
 * 1213
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
int n;
vi w(1005), v(1005);
vector<vii> dp(1005, vii(3005, -1));

ll backtrack(int i, int s = 0) {
  if (i < 0 || s > 3000) {
    return 0;
  }
  if (dp[i][s] == -1) {
    // skip
    dp[i][s] = backtrack(i - 1, s);
    //include
    if (s <= v[i]) {
      dp[i][s] = max(dp[i][s], 1 + backtrack(i - 1, s + w[i]));
    }
  }
  return dp[i][s];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(cin >> n, n) {
    rep(i,0,n) {
      cin >> w[i] >> v[i];
      dp[i].assign(3005, -1);
    }
    ll res = backtrack(n - 1);
    cout << res << "\n";
  }
}
