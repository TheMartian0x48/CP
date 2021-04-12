/*
 * TheMartian0x48
 * Uva 12169
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

  int n, mod = 10001; cin >> n;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  vector<int> v, u(n); re(v, n);
  for (int i = 0; i < mod; i++) {
    for (int j = 0; j < mod; j++) {
      int k = 1;
      u[0] = (i * v[0] + j) % mod;
      while (k < n) {
        int x = (i * u[k-1] + j) % mod;
        if (x != v[k]) break;
        u[k] = (i * v[k] + j) % mod;
        k++;
      }
      if (k == n) {
        for (auto a : u) cout << a << "\n";
        return 0;
      }
    }
  }
}
