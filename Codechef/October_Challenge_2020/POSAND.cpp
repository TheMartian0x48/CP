/*
 *TheMartian0x48
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
// -----------------

void solve() {
  int n; cin >> n;
  if (n <= 1) {
    cout << 1 << endl;
  }
  if (!(n & (n - 1))) {
    cout << -1 << endl;
    return;
  }
  int b = 1;
  while ((b << 1) < n) b <<= 1;
  for (int i = b + 2; i <= n; i++) cout << i << " ";
  cout << b << " " << b + 1 << " ";
  
  int t = 1;
  while (t < b) {
    for (int i = 2 * t - 1; i >= t; i--) cout << i << " ";
    t *= 2;    
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test; cin >>  test;
  while (test--)  
    solve();
}
