/*
 * TheMartian0x48
 * Uva 13054
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

// ---------------- (* Extract here *)
// ----------------
vi v(100005);

void solve() {
  int n, h, ta, tb; cin >> n >> h >> ta >> tb;
  rep(i,0,n) cin >> v[i];
  if (2 * ta <= tb) {
    cout << n * ta << "\n";
    return;
  }

  int i = 0, j = n - 1;
  ll res = 0;
  sort(v.begin(), v.begin() + n);
  while (i <= j) {
    if (i != j && v[j] + v[i] < h) {
      res += tb;
      j--, i++;
    } else {
      j--;
      res += ta;
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // clang-format off
  int test, i = 1;
  cin >> test;
  while (test--) {
    cout << "Case " << i++ << ": ";
    solve();
  }
  // clang-format on
}
