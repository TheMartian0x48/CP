/*
 * TheMartian0x48
 * USACO 2016 US Open Contest, Silver
 * Problem 3. Closing the Farm
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

int n,nmax=3005;
vector<vector<int>> g(nmax);
vector<bool> used;

void dfs(int v = 0) {
  used[v] = true;
  for(auto u : g[v]) {
    if (used[u] || (g[u].size() == 1 && g[u][0] == -1)) continue;
    dfs(u);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("closing");

  int m; cin >>n >> m;
  int a, b;
  rep(i,0,m) cin >> a >> b, a--, b--, g[a].push_back(b), g[b].push_back(a);
  while(cin >> a) {
    a--;
    b = 0;
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (used[i] == false && g[i][0] != -1) {
        b++;
        dfs(i);
      }
    }
    if (b == 1) cout << "YES\n";
    else cout << "NO\n";
    g[a].clear();
    g[a].push_back(-1);
  }
}
