/*
 * TheMartian0x48 
 * USACO 2015 December Contest, Gold
 * Problem 1. High Card Low Card (Gold)
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

  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);

  int n; cin >> n;
  vi f(2 * n + 1, 0);
  vi e(n), b;
  rep(i,0,n) cin >> e[i], f[e[i]] = 1;
  rep(i,1,2*n+1) {
    if (f[i] == 0)
      b.push_back(i);
  }

  int res = 0;
  sort(e.begin(), e.begin() + n / 2);
  sort(e.begin() + n / 2, e.end());
  set<int> st;
  rep(i, n/2, n) {
    st.insert(b[i]);
  }
  per(i,n/2 - 1, 0) {
    auto it = st.lower_bound(e[i]);
    if (it == st.end()) st.erase(*st.begin());
    else st.erase(*it), res++;
  }
  rep(i,0,n/2) st.insert(b[i]);
  rep(i, n/2, n) {
    auto it = st.lower_bound(e[i]);
    if (it == st.begin()) st.erase(*st.rbegin()) ;
    else st.erase(*(--it)), res++;
  }
  cout << res;
}
