/*
 * TheMartian0x48
 * UVa 11001
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

  int a, b;
  while (cin >> a >> b, a || b) {
    int N = ceil((a + 0.0) / b);
    double mx = 0;
    int c = 0, res = 0;
    for (int i = 1; i <= N; i++) {
      double v = (a + 0.0) / i;
      double d  = 0.3 * sqrt(v - b);
      d *= i;
      if ( abs(d - mx) < 1e-6)
        c++;
      else if ((d - mx) > 1e-6)
        mx = d, c = 1, res = i;
    }
    if (c == 1)
      cout << res << "\n";
    else cout << 0 << "\n";
  }
}
