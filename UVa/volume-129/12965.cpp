/*
 * TheMartian0x48
 * Uva 12965
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

  int test; cin >> test;
  vi c(10005), p(10005), b(20005);
  while (test--) {
    int n, m; cin >> n >> m;
    b[0] = 0;
    int k = 1;
    rep(i,0,n)
      cin >> p[i], b[k++] = p[i];
    rep(i,0,m)
      cin >> c[i], b[k++] = c[i];
    sort(c.begin(), c.begin() + m);
    sort(p.begin(), p.begin() + n);
    sort(b.begin(), b.begin() + k);

    int res = 0, mi = k;
    for (int i = 0; i < k; i++) {
      int tmp = 0;

      int j = upper_bound(p.begin(), p.begin() + n, b[i]) - p.begin();
      tmp = n - j;
      j = lower_bound(c.begin(), c.begin() + m, b[i]) - c.begin();
      tmp += j;
      if (tmp < mi)
        mi = tmp, res = b[i];
    }
    cout << res << " " <<  mi << "\n";
  }
}
