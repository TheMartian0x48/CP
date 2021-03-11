/*
 * TheMartian0x48 
 * USACO 2017 February Contest, Silver
 * Problem 3. Why Did the Cow Cross the Road III
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
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on
int n;
vector<vi> g(105, vi(105, 0)), dp(105,vi (105, 0));

void dfs(int r, int c, int k) {
  if (dp[r][c]) return;
  dp[r][c] = k;
  int t = g[r][c];
  if (!(t & 1)) dfs(r, c + 1, k);
  if (!(t & 8)) dfs(r, c - 1, k);
  if (!(t & 2)) dfs(r + 1, c, k);
  if (!(t & 4)) dfs(r - 1, c, k);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("countcross.in", "r", stdin);
  freopen("countcross.out", "w", stdout);

  int k, r; cin >> n >> k >> r;
  for (int i = 1; i <= n; i++) {
    g[i][1] |= 8;
    g[i][n] |= 1;
    g[1][i] |= 4;
    g[n][i] |= 2;
  }
  int c1, r1, c2, r2;
  for (int i = 0; i < r; i++) {
    cin >> r1 >> c1 >> r2 >> c2;
    if (c1 + 1 == c2) {
      g[r1][c1] |= 1;
      g[r2][c2] |= 8;
    } else if (c2 + 1 == c1) {
      g[r1][c1] |= 8;
      g[r2][c2] |= 1;
    } else if (r1 + 1 == r2) {
      g[r1][c1] |= 2;
      g[r2][c2] |= 4;
    } else {
      g[r1][c1] |= 4;
      g[r2][c2] |= 2;
    }
  }
  int c = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] == 0) {
        dfs(i, j, c++);
      }
    }
  }
  vector<pii> cow(k);
  for (int i = 0; i < k; i++) {
    cin >> cow[i].first >> cow[i].second;
  }
  int res = 0;
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      res += dp[cow[i].first][cow[i].second] != dp[cow[j].first][cow[j].second];
    }
  }
  cout << res;
}
