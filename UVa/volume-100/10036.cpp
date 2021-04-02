/*
 * TheMartian0x48
 * UVa 10036
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

int n, k;
vector<int> v(10005);
vector<vector<bool>> dp(10005, vector<bool>(105));

void solve() {
  cin >> n >> k;
  rep(i,0,n) {
    cin >> v[i];
    v[i] = (v[i] % k + k) % k;
    dp[i].assign(k, false);
  }
  dp[0][v[0]] = true;
  rep(i,1,n) {
    rep(j,0,k) {
      if (dp[i - 1][j]) {
        int r = (j + v[i]) % k;
        dp[i][r] = true;
        r = ((j - v[i]) % k + k) % k;
        dp[i][r] = true;
      }
    }
  }
  
  if (dp[n - 1][0]) cout << "Divisible\n";
  else cout << "Not divisible\n";
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
