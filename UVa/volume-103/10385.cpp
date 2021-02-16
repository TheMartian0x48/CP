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
int n; 
vector<pair<double, double>> v(25);
double t;

double f(double x) {
  double sec = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    sec = min(sec, 3600 * x/v[i].first + 3600 * (t - x)/v[i].second);
  }
  double cheater = 3600 * x / v[n - 1].first + 3600 * (t - x) / v[n - 1].second;
  return sec - cheater;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  while (cin >> t) {
    double l = 0, r;
    cin >> n;
    rep(i,0,n) cin >> v[i].first >> v[i].second;
    r = t;
    for (int i = 0; i < 200; i++) {
      double m1 = (2 * l + r) / 3;
      double m2 = (l + 2 * r) / 3;
      double v1 = f(m1);
      double v2 = f(m2);

      if (v1 > v2) 
        r = m2;
      else 
        l = m1;
    }
    int sec = round(f(l));
    if (sec < 0) {
      printf("The cheater cannot win.\n");
    } else {
      printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n", sec, l, t - l);
    }
  }
}

