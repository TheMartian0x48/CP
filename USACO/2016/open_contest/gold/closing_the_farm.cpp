
/*
 * TheMartian0x48
 * USACO 2016 US Open Contest, Gold
 * Problem 2. Closing the Farm
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


struct dsu{
  int n;
  vector<int> par, size;
  dsu(int s){
    n = s;
    par.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    par[b] = a;
    return true;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("closing");

  int n, m; cin >> n >> m;
  dsu st(n);
  vector<vi> g(n);
  int a, b;
  while (m--) {
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi v;
  re(v, n);
  int c = 0;
  vector<bool> vis(n, false);
  string res;
  per(i,n-1,0) {
    int u = v[i] - 1;
    c++;
    vis[u] = true;
    for (auto e : g[u]) {
      if (vis[e]) {
        c -= st.merge(u, e);
      }
    }
    if (c != 1) {
      res += '0';
    } else {
      res += '1';
    }
  }
  for (int i = sz(res) - 1; i >=0; i--){
    if (res[i] == '0') cout << "NO\n";
    else cout << "YES\n";
  }
}
