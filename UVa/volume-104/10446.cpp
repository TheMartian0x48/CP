/*
 * TheMartian0x48
 * UVa 10446
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
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<unsigned long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
// clang-format on

vector<vii> dp(62, vii(62, 0));

ll cs(int n, int k) {
  if (n <= 1) return 1;
  if (dp[n][k] != 0L) return dp[n][k];
  ll res = 1;
  for (int i = 1; i <= k; i++) {
    res += cs(n - i, k);
  }
  return dp[n][k] = res;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, i = 1;
  while (cin >> a >> b) {
    if (a > 60) break;
    cout << "Case " << i++ << ": ";
    cout << cs(a, b) <<"\n";
  }
}
