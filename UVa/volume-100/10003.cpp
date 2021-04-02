/*
 * TheMartian0x48
 * UVa 10003
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
int len, MAX = 1e7;
vector<int> v(55);
vector<vi> dp(55, vi(55));
int cs(int i, int j) {
  if (i == j - 1) return 0;
  if (dp[i][j] != INT_MAX) return dp[i][j];
  int res = INT_MAX;
  for (int k = i + 1; k < j; k++) {
    int left = cs(i, k);
    int right = cs(k, j);
    res = min(res, left + right - v[i] + v[j]);
  }
  return dp[i][j] = res;
}

void solve() {
  int n; cin >> n;
  v[0] = 0;
  rep(i,1,n+1) cin >> v[i];
  v[n + 1] = len;
  rep(i,0,n+1) dp[i].assign(55, INT_MAX);
  cout << "The minimum cutting is " << cs(0, n + 1) << ".\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin>>len, len) solve();
}
