
/*
 * TheMartian0x48
 * USACO 2017 US Open Contest, Silver
 * Problem 1. Paired Up
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
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("pairup");

  int n; cin >> n;
  vector<pii> v(n);
  rep(i,0,n) cin >> v[i].second >> v[i].first;
  sort(all(v));
  ll res = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    res = max(res, 0LL + v[i].first + v[j].first);
    if (v[i].second > v[j].second) v[i].second -= v[j].second, j--;
    else if (v[i].second < v[j].second) v[j].second -= v[i].second, i++;
    else i++, j--;
  }
  cout << res;
}
