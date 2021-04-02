/*
 * TheMartian0x48
 * UVa 10912
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

vector<vector<vi>> dp(27, vector<vi>(375, vi(27, -1)));

int cs(int n, int s, int k = 26) {
  if (s < 0) return 0;
  if (n == 0) return s == 0;
  else if (k <= 0) return 0;
  else if (dp[n][s][k] != -1) return dp[n][s][k];
  int res = 0, t = k;
  while(k) {
    if (s - k >= 0)
      res += cs(n - 1, s - k, k - 1);
    k--;
  }
  return dp[n][s][t] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, test = 1;
  while (cin >> a >> b, a) {
    cout << "Case " << test++ << ": ";
    if (a > 26 || b > 371) cout << 0 << "\n";
    else {
      cout << cs(a, b) << endl;
    }
  }
}
