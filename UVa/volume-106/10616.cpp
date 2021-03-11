/*
 * TheMartian0x48
 * Uva 10616
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
using ll = unsigned long long;
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
int n, q, d, m;
vi v(205);
vector<vector<vii>> dp(205, vector<vii>(25, vii(15)));

ll backtrack(int i, int s = 0, int c = 0) {
  if (i < 0) {
    return c == m && s % d == 0;
  }
  if (dp[i][s][c] != -1) return dp[i][s][c];
  // skip
  dp[i][s][c] = backtrack(i - 1, s, c);
  // include
  if (c < m)
    dp[i][s][c] += backtrack(i - 1, ((s + v[i]) % d + d) % d, c + 1);
  return dp[i][s][c];
}

void solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= d; j++) {
      dp[i][j].assign(m + 1, -1);
    }
  }
  ll t = backtrack(n - 1);
  cout << t << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  for (int test = 1;; test++) {
    cin >> n >> q;
    if (!n && !q) break;
    cout << "SET " << test << ":\n";
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i <= q; i++) {
      cout << "QUERY " << i << ": ";
      cin >> d >> m;
      solve();
    }
  }
}
