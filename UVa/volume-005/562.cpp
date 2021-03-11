/*
 * TheMartian0x48
 * UVa 562
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
int n, tar, sum;
vi v(105);
vector<vi> dp(100, vi(25005));
int divide(int i, int s = 0) {
  if (i < 0) return s;
  if (dp[i][s] != -1) 
    return dp[i][s];
  //exclude
  dp[i][s] = divide(i - 1, s);
  // include
  if (s + v[i] <= tar)
    dp[i][s] = max(dp[i][s], divide(i - 1, s + v[i]));
  return dp[i][s];
}

void solve() {
  cin >> n;
  sum = 0;
  rep(i,0,n) {
    cin >> v[i];
    sum += v[i];
  }
  tar = (sum + 1) / 2;
  rep(i,0,n) {
    dp[i].assign(tar + 1, -1);
  }
  int t = divide(n - 1);
  cout << abs(sum - t - t) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // clang-format off
  int test;
  cin >> test;
  while (test--)
    solve();
  // clang-format on
}
