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
vector<pii> v;
int n, t;
const double epi = 1e-6;

bool good(double c) {
  double tt = 0;
  for (auto&p : v) {
    tt += p.first / (p.second + c);
  }
  return tt > t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  while(cin >> n >> t) {
    v.resize(n);
    double l = INT_MAX, r = 1e9;
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
      l = min(l, (double)v[i].second);
    }
    l = 0 - l;
    for (int i = 0; i < 100; i++) {
      double m = (l + r) / 2;
      if (good(m)) l = m;
      else r = m;
    }
    printf("%.9lf\n", l);
  }
}

