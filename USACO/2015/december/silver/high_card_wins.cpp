/*
 * TheMartian0x48
 * USACO 2015 December Contest, Silver
 * Problem 2. High Card Wins
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

  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);
  int n; cin >> n;
  vi a(n), p(2 * n + 1, 0);
  rep(i,0,n) {
    cin >> a[i];
    p[a[i]] = 1;
  }
  set<int> st;
  rep(i,1,2*n+1) {
    if (p[i] == 0)
      st.insert(i);
  }
  sort(all(a));
  int res = 0;
  per(i,n-1,0) {
    auto it = st.lower_bound(a[i]);
    if (it == st.end()) {
      st.erase(*st.begin());
    } else {
      st.erase(*it);
      res++;
    }
  }
  cout << res;
}
