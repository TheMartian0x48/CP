/*
 * TheMartian0x48 
 * 12834
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tests; cin >> tests;
  int nmax = 1e6+5;
  vii a(nmax), b(nmax), c(nmax);

  for (int test = 1; test <= tests; test++) {
    cout << "Case " << test << ": ";
    int n, k;
    cin >> n >> k;
    re(a, n);
    re(b, n);
    rep(i,0,n) {
      c[i] = b[i] - a[i];
    }
    sort(c.begin(), c.begin() + n);
    ll res = 0;
    int i = n - 1;
    while (i >= k) {
      res += c[i];
      i--;
    }
    while (i >= 0 && c[i] > 0) {
      res += c[i];
      i--;
    }
    if (res > 0) {
      cout << res;
    } else {
      cout << "No Profit";
    }
    cout << "\n";
  }
}
