/*
 * TheMartian0x48
 * UVa 11450
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
// clang-format on

vector<vi> v(25);
vector<vi> dp(25);
int cs(int m, int i) {
  if (i < 0) return 0;
  if (dp[i][m] != -1) return dp[i][m];
  for (auto c : v[i]) {
    if (c <= m) {
      int r = cs(m - c, i - 1);
      if (r >= 0)
        dp[i][m] = max(r + c, dp[i][m]);
    }
  }
  return dp[i][m];
}

void solve() {
  int m, c; cin >> m >> c;  
  rep(i,0,c) {
    int k;   cin >> k;
    v[i].clear();
    while (k--) {
      int t; cin >> t; v[i].push_back(t);
    }
    dp[i].assign(m + 1, -1);
  }
  auto res = cs(m, c - 1);
  if (res == -1) cout << "no solution\n";
  else cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
