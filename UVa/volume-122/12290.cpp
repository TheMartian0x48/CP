/*
 * TheMartian0x48
 * UVa 12290
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

bool valid(ll n) {
  if (n % 7== 0) return true;
  while (n) {
    int d = n % 10;
    if (d == 7) return true;
    n /= 10;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k;
  while (cin >> n >> m >> k, n || m || k) {
    ll res = m, dir = 1, i = m;
    while (1) {
      if (valid (res)) k--;
      if (k == 0) break;
      do {        
        if (i == 1) {
          dir = 1;
        } else if (i == n) {
          dir = -1;
        }
        i += dir;
        res++;
      } while (i != m);
    }
    cout << res << "\n";
  }
}
