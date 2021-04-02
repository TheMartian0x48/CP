/*
 * TheMartian0x48
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

vector<unordered_set<int>> v(3);

void solve() {
  int t, l, r, s; cin >> l >> r >> s;
  rep(i,0,3) v[i].clear();
  rep(i,0,l) cin >> t, v[0].insert(t);
  rep(i,0,r) cin >> t, v[1].insert(t);
  rep(i,0,s) cin >> t, v[2].insert(t);
  vi res1(3, 0), res2(3, 0);
  int j, k;
  rep(i, 0, 3) {
    for (auto a : v[i]) {
      j = (i + 1) % 3;
      k = (i + 2) % 3;
      bool f = v[j].find(a) != v[j].end();
      bool ff = v[k].find(a) != v[k].end();
      if (!f && !ff) {
        res1[i]++;
      } else if (f && !ff) {
        res2[k]++;
      } else if (!f && ff) {
        res2[j]++;
      }
    }
  }
  rep(i,0,3) {
    cout << res1[i] << " " << res2[i] / 2 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // clang-format off
  int test, i = 1;
  cin >> test;
  while (test--) {
    cout << "Case #" << i++ << ":\n";
    solve();
  }
  // clang-format on
}
