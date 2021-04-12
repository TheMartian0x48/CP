/*
 * TheMartian0x48
 * 616
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

  ll n;
  while (cin >> n, n >= 0) {
    cout << n << " coconuts, ";
    int res = -1;
    for (int i = 2; i < 20; i++) {
      ll t = n; 
      bool sol = true;
      for (int j = 0; j < i; j++) {
        t--;
        if (t % i != 0) {
          sol = false;
          break;
        }
        t = t - t / i;
      }
      if (sol && t % i == 0) res = i;
    }
    if (res == -1) cout << "no solution\n";
    else cout << res << " people and 1 monkey\n";
  }
}
