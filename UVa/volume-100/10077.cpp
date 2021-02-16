/*
 *TheMartian0x48
 * 679
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

int good(ll a1, ll a2, ll b1, ll b2) {
  if (a1 == b1 && a2 == b2) return 0;
  if (a1 * b2 < a2 * b1) return -1;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll l, r;
  while(true) {
    cin >> l >> r;
    if (l == 1 && r == 1) break;
    ll g = __gcd(l, r);
    l /= g;
    r /= g;
    if (l == r) {
      cout << "I" << "\n";
      continue;
    }
    string res;

    ll l1 = 0, l2 = 1, r1 = 1, r2 = 0;
    while (true) {
      ll m1 = l1 + r1, m2 = l2 + r2;
      int response = good(l, r, m1, m2);
      if (!response) break;
      else if (response == -1) {
        res += 'L';
        r1 = m1, r2 = m2;
      } else {
        res += 'R';
        l1 = m1, l2 = m2;
      }
    }
    cout << res << "\n";
  }
}

