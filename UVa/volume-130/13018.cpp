/*
 * TheMartian0x48
 * UVa 13018
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  bool f = true;
  while (cin >> n >> m) {
    if (!f) cout << "\n";;
    f = false;
    vi v(n + m + 5, 0);
    int mx = 0;
    rep(i,0,n) rep(j,0,m) v[i + j + 2]++, mx = max(mx, v[i + j + 2]);
    rep(i,0,n + m + 5) {
      if (v[i] == mx) cout << i << "\n";
    }
  }
}
