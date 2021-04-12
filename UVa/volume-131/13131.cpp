/*
 * TheMartian0x48
 * UVa 13131
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

void solve() {
  int n, k; cin >> n >> k;
  ll res = 0;
  int up = sqrt(n);
  for (int i = 1; i <= up; i++) {
    if (n % i == 0) {
      if (i % k) res += i;
      int d = n / i;
      if (i != d && d % k) res += d;
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  // int testcase = 1;
  cin >> test;
  while (test--) {
    // cout << "Case #" << testcase++ << ": ";
    solve();
  }
}
