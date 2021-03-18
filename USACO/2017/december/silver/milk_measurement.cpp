/*
 * TheMartian0x48
 * USACO 2017 December Contest, Silver
 * Problem 2. Milk Measurement
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
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);}
// clang-format on


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("measurement");

  int n; cin >> n;
  ll g; cin >> g;
  vector<pair<int, pair<ll, ll>>> v(n);
  rep(i,0,n) cin >> v[i].first >> v[i].second.first >> v[i].second.second;
  sort(all(v));
  
  multiset<ll> mx;
  unordered_map<ll, ll> cow;

  rep(i,0,n) mx.insert(g), cow[v[i].second.first] = g;
  mx.insert(g);
    

  ll res = 0;
  for (int i = 0; i < n; i++) {
    ll milk = cow[v[i].second.first];
    ll nmilk = milk + v[i].second.second;
    if (nmilk == milk) continue;
    ll m = *mx.rbegin();
    if (milk == m) {
      int c = mx.count(m);
      if (c > 1) {
        res++;
        cow[v[i].second.first] = nmilk;
        mx.erase(mx.find(m));
        mx.insert(nmilk);
      } else {
        mx.erase(mx.find(m));
        if (*mx.rbegin() >= nmilk) {
          res++;
        }
        mx.insert(nmilk);
        cow[v[i].second.first] = nmilk;
      }
    } else {
      if (nmilk >= m) res++;
      mx.erase(mx.find(milk));
      mx.insert(nmilk);
      cow[v[i].second.first] = nmilk;
    }
  }
  cout << res;
}
