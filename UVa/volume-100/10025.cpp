/*
 * TheMartian0x48
 * UVa 10025
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
  ll n; cin >> n;
  n = abs(n);
  ll l = 0, r = 1e9;
  while(l + 1 < r) {
    ll m = (l + r) / 2;
    ll s = m * (m + 1) / 2 ;
    if (s < n) l = m;
    else r = m;
  }
  ll s = r * (r + 1) / 2;
  while ((s - n) & 1) {
    r++;
    s = r * (r + 1) / 2;
  }
  cout << r << "\n";
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
    if (test) cout << "\n";
  }
}
