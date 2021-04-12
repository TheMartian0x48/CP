/*
 * TheMartian0x48
 * UVa 10721
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

vector<vector<vii>> dp(51, vector<vii>(51, vii(51, -1)));

ll cs(int n, int k, int m) {
  if (k == 1) return n > 0 && n <= m;
  if (k < 0 || n < 1) return 0;
  if (dp[n][k][m] != -1) return dp[n][k][m];
  ll res = 0;
  for (int i = 1; i <= m; i++) {
    res += cs(n - i, k - 1, m);
  }
  return dp[n][k][m] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, m;
  while (cin >> n >> k >> m) {
    cout << cs(n, k, m) << "\n";
  }
}
