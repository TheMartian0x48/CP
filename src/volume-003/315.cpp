// @author: the__martian
// 315

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

int n;
vector<vi> g(105);
vector<bool> visited, cut;
vi in, low;
int timer, res;

void dfs(int u, int p = -1) {
  visited[u] = true;
  low[u] = in[u] = timer++;
  int child = 0;

  for (auto v : g[u]) {
    if (v == p) continue;
    if (visited[v]) {
      low[u] = min(low[u], in[v]);
    } else {
      child++;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= in[u] && p != -1)
        cut[u] = true;
    }
  }
  if (child > 1 && p == -1 )
    cut[u] = true;
}

void articulate(){
  in.assign(n + 1,1);
  low.assign(n + 1,1);
  visited.assign(n + 1, false);
  cut.assign(n, false);
  timer = 1, res = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    res += cut[i];
  }
  for (int i = 0; i < 105; i++) g[i].clear();
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  string s;
  while (getline(cin, s), s != "0") {
    n = stoi(s);
    while (getline(cin, s), s != "0") {
      stringstream ss(s);
      int u; ss >> u;
      int v;
      while (ss >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    articulate();
    cout << res << "\n";
  }
}
