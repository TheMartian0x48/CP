/*
 * TheMartian0x48
 * UVa 10943
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

int mod = 1000000;
vector<vector<int>> dp(105, vector<int>(105, -1));

int cs(int n, int k) {
  if (k == 0) return n == 0;
  if (dp[n][k] != -1) return dp[n][k];
  dp[n][k] = 0;
  for (int i = 0; i <= n; i++) {
    dp[n][k] += cs(n - i, k - 1);
    dp[n][k] %= mod;
  }
  return dp[n][k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  while (cin >> n >> k, n || k)
    cout << cs(n, k) << "\n";
}
