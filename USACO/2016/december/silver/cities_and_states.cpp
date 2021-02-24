/*
 * TheMartian0x48
 * USACO 2016 December Contest, Silver 
 * Problem 2. Cities and States
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

  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);

  unordered_map<string, unordered_multiset<string>> mp;
  int n; cin >> n;
  rep(i,0,n) {
    string c, s;
    cin >> c >> s;
    mp[s].insert(c.substr(0, 2));    
  }

  int res = 0;
  for (auto &p : mp) {
    string s = p.first;
    for (auto &c : p.second) {
      if (c == s) continue;
      auto it = mp.find(c);
      if (it != mp.end()) {
        res += it->second.count(s);
      }
    }
  }
  cout << res / 2;
}
