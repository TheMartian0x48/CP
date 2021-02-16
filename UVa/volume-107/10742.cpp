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

  string s; cin >> s;
  int q; cin >> q;
  unordered_map<char, vi> v;
  for (int i =  0; i < sz(s); i++) {
    v[s[i]].push_back(i);
  }

  while(q--) {
    cin >> s;
    int n = sz(s);
    if (v[s[0]].size() == 0) {
      cout << "Not matched\n";
      continue;
    }
    bool sol = true;
    int first = v[s[0]][0];
    int last = first;
    for (int i = 1; i < n; i++) {
      int id = lower_bound(all(v[s[i]]), last + 1) - v[s[i]].begin();
      if (id == v[s[i]].size()) {
        sol = false;
        break;
      } else {
        last = v[s[i]][id];
      }
    }
    if (sol) {
      cout << "Matched " << first << " " << last << "\n";
    } else {
      cout << "Not matched\n";
    }
  }
}

