// @author: the__martian
// 11080
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

vector<vi> g(201);
int n, t, f;
vector<bool> visited, color;

bool check(int u, int p = -1) {
  visited[u] = true;
  for (auto v : g[u]) {
    if (p == v) continue;
    if (visited[v]) {
      if (color[v] == color[u])
        return false;
      continue;
    }
    color[u] ? f++ : t++;
    color[v] = !color[u];
    if (check(v, u) == false) return false;
  }
  return true;
}

int bipartite() {
  visited.assign(n, false), color.assign(n, false);
  
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      f = 1, t = 0;
      if (check(i) == false)
        return -1;
      else {
        res += min(t, f);
        if (t==0)
          res++;
      }
    }
  }
  return res;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> n >> m;
    rep(i,0,m) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    cout << bipartite() << endl;
    rep(i,0,205)
      g[i].clear();
  }

}
