// @author: the__martian
// 796
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

int N = 10e3, timer, n;
vector<vi> g(N);
vi low, in;
vector<bool> visited;
vector<pii> link;

void dfs(int u, int p = -1) {
  visited[u] = true;
  in[u] = low[u] = timer++;
  for (auto v : g[u]) {
    if (p == v) continue;
    if (visited[v]) {
      low[u] = min(low[u], in[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > in[u]) {
        link.push_back({min(u,v), max(u,v)});
      }
    }
  }
}
void bridge() {
  in.assign(n, 0), low.assign(n, 0);
  visited.assign(n, false);
  timer = 1;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  
  sort(all(link));
}




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < N; i++)
      g[i].clear();
    link.clear();
    int u, m, v;
    for (int i = 0 ; i < n;  i++) {
      scanf("%d (%d) ", &u, &m);
      for (int j = 0; j < m; j++) {
        scanf("%d", &v);
        g[u].push_back(v);
      }
    }
    bridge();
    printf("%d critical links\n", (int)link.size());
    for (auto p : link) {
      printf("%d - %d\n", p.first, p.second);
    }
    printf("\n");
  }
} 