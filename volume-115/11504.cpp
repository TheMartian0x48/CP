// @author: the__martian
// 11504
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

int n, m, N = 1e5 + 5;
vector<vi> g(N);
vector<bool> visited;
stack<int> st;

void dfs(int u) {
  visited[u] = true;
  for (auto v : g[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
  st.push(u);
}

void Kosaraju() {

  visited.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      dfs(i);
    }
  }
  visited.assign(n, false);
  int res = 0;
  while (st.size()) {
    int u = st.top(); st.pop();
    if (visited[u] == false) {
      dfs(u);
      res++;
    }
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    rep(i,0,m) {
      int a, b;
      cin >> a >> b;
      g[a - 1].push_back(b - 1);
    }
    Kosaraju();
    for (int i = 0; i < n; i++)
      g[i].clear();
  }
}