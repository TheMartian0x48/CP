/*
 * TheMartian0x48
 * USACO 2018 December Contest, Silver
 * Problem 2. Convention II
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

  freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);

  int n; cin >> n;
  vector<pair<ll, pair<ll, ll>>> v(n);
  priority_queue<pair<ll, pair<ll, ll>>> pq;

  for (int i  = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second.first;
    v[i].second.second = -i;
  }
  sort(all(v));
  ll res = 0;
  ll time = v[0].first + v[0].second.first;
  
  int i = 1;
  while (i < n) {
    while (i < n && v[i].first <= time) {
      pq.push({v[i].second.second, {v[i].first, v[i].second.first}});
      i++;
    }
    if (pq.empty() && i < n) {
      time = v[i].first;
    } else if (pq.size()) {
      auto start = pq.top().second.first;
      auto t = pq.top().second.second;
      res = max(res, time - start);
      time += t;
      pq.pop();
    }
  }

  while (pq.size()) {
    auto start = pq.top().second.first;
      auto t = pq.top().second.second;
      res = max(res, time - start);
      time += t;
      pq.pop();
  } 

  cout << res;
}
