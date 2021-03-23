
/*
 * TheMartian0x48
 * USACO 2018 January Contest, Silver
 * Problem 3. MooTube
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
int n, r;
vector<vector<pii>> g(5005);
vector<bool> vis(5005, false);

int dfs(int v) {
  vis[v] = true;
  int res = 1;
  for (auto a : g[v]) {
    if (vis[a.first] == false && a.second >= r) {
      res += dfs(a.first);
    }
  }
  vis[v] = false;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("mootube");

  int q; cin >> n >> q;
  rep(i,0,n-1){
    int a, b, c; cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  rep(i,0,q) {
    int v; cin >> r >> v;
    int res = dfs(v);
    cout << res - 1 << "\n";
  }
}
