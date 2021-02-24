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

  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);

  vector<string> cow{"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie","Henrietta"};
  unordered_map<string, int> mp;
  for (auto c : cow) 
    mp[c] = 0;

  int n; cin >> n;
  rep(i,0,n) {
    string c; cin >> c;
    int m; cin >> m;
    mp[c] += m;
  }
  vector<pair<int, string>> v;
  for (auto p: mp) {
    v.push_back({p.second, p.first});
  }
  sort(all(v));
  int i = 1;
  while (i < 7 && v[i].first == v[i - 1].first) i++;
  if (i == 7 || (i + 1 < 7 && v[i].first == v[i + 1].first)) {
    cout << "Tie\n";
    return 0;
  }
  cout << v[i].second << "\n";
}
