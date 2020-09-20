// @author: the__martian
// 11396
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int N = 305, n;
vector<vi> g(N);
vector<bool> visited,color;

bool dfs(int u, int p = -1) {
  visited[u] = true;

  for (auto v : g[u]) {
    if (v == p) continue;
    if (visited[v]) {
      if (color[u] == color[v]) return false;
    } else {
      color[v] = !color[u];
      if (!dfs(v, u)) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> n, n) {
    for (int i = 0; i  < n; i++)
      g[i].clear();
    int u, v;
    while (cin >> u >> v, u && v) {
      g[u - 1].push_back(v - 1);
      g[v - 1].push_back(u - 1);
    }
    visited.assign(n, false);
    color.assign(n, false);
    bool bp = true;
    for (int i = 0; i < n && bp; i++) {
      if (visited[i] == false)
        bp = dfs(i);
    }
    cout << (bp ?  "YES" : "NO") << endl;
  }
}