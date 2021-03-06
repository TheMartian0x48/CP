/*
 * TheMartian0x48
 * USACO 2015 December Contest, Gold
 * Problem 2. Fruit Feast
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

ll t, a, b;
const int T = 5e6+5;
vector<vector<bool>> dp(2, vector<bool>(T, false));

void solve() {
    stack<pii> st;
    st.push({0, 0});
    while (st.size()) {
      auto p = st.top();
      st.pop();
      if (dp[p.second][p.first] == false) {
        if (p.first + a <= t)
          st.push({p.first + a, p.second});
        if (p.first + b <= t)
          st.push({p.first + b, p.second});
        if (p.second == 0) {
          st.push({p.first / 2, 1});
        }
      }
      dp[p.second][p.first] = true;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  cin >> t >> a >> b;
  solve();
  int res = 0;
  for (int i = 0; i <= t; i++) {
    if (dp[0][i] || dp[1][i])
      res = i;
  }
  cout << res;
}
