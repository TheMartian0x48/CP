/*
 * TheMartian0x48
 * USACO 2019 December Contest, Bronze
 * Problem 2. Where Am I?
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int n; cin >> n;
  string s; cin >> s;
  unordered_set<string> st;
  int i = 0;
  for (i = 1; i <= n; i++) {
    st.clear();
    bool sol = true;
    for (int j = 0; j + i <= n; j++) {
      string t = s.substr(j, i);
      if (st.count(t)) {
        sol = false;
        break;
      }
      st.insert(t);
    }
    if (sol) {
      cout << i;
      return 0;
    }
  }
}
