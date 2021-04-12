/*
 * TheMartian0x48
 * UVa 12205
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

  int N = 10005;
  vector<pii> v(N);
  int n, m;
  while (cin >> n >> m, n || m) {
    rep(i,0,n) cin >> v[i].first >> v[i].second >> v[i].first >> v[i].second, v[i].second += v[i].first;
    sort(v.begin(), v.begin() + n);
    while(m--) {
      int a, b; cin >> a >> b;
      b += a;
      int res = 0;
      for (int i = 0; i < n; i++) {
        if ((v[i].first >= a && v[i].first < b) || (v[i].second > a && v[i].second <= b))
          res++;
        else if (v[i].first <= a && v[i].second >= b) res++;
        if (v[i].first >= b) break;
      }
      cout << res << "\n";
    }
  }
}
