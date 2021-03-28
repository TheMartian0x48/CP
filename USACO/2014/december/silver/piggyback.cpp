 /*
  * USACO 2014 December Contest, Silver
  * Problem 1. Piggyback
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
// clang-format on

vector<vi> g;

void bfs(int s, vi& dis) {
  queue<int> q; q.push(s);
  dis[s] = 0;
  while(q.size()) {
    int u = q.front(); q.pop();
    for (auto a : g[u]) {
      if (dis[a] > dis[u] + 1) {
        dis[a] = dis[u] + 1;
        q.push(a);
      }
    }
  }
}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("piggyback");

  int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
  p = min(p, b + e);
  g.resize(n + 1);

  while (m--) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi dis1(n + 1, INT_MAX);
  vi dis2(n + 1, INT_MAX);
  vi dis3(n + 1, INT_MAX);

  bfs(1, dis1);
  bfs(2, dis2);
  bfs(n, dis3);
  ll res = INT_MAX;
  for (int i = 1; i <= n; i++) {
    res = min(res,0LL + b * dis1[i] + e * dis2[i] + p * dis3[i]);
  }
  cout << res;
}
