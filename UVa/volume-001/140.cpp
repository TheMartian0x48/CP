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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  vector<unordered_set<int>> g(26);
  while (cin >> s, s != "#") {
    vi v;
    for (int i =0; i < 26; i++) g[i].clear();
    for (int i = 0; i < sz(s);) {
      if (s[i] == ';') {
        i++;
        continue;
      }
      int u = s[i] - 'A';
      i += 2;
      while (i < sz(s) && s[i] != ';') {
        g[u].insert(s[i] - 'A');
        g[s[i] - 'A'].insert(u);
        i++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (g[i].size()) v.push_back(i);
    }
    vi res;
    int band = INT_MAX;
    unordered_map<int, int> mp;
    do {
      int mi = 0;
      mp.clear();
      for (int i = 0; i < sz(v); i++) mp[v[i]] = i;
      for (int i = 0; i < sz(v); i++) {
        for (auto u : g[v[i]]) mi = max(mi, abs(mp[u] - mp[v[i]]));
      }
      if (mi < band) band = mi, res = v;
    } while (next_permutation(all(v)));
    for (auto u : res) cout << (char)('A' + u) << " ";
    cout << "-> " << band << "\n";
  }
}