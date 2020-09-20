// @author: the__martian
// 11838
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

vector<vi> g(2005), rg(2005);
int n;
vector<bool> visited;
stack<int> st;

void Dfs(int u, int put = 0) {
  visited[u] = true;
  if (put) { 
    for (auto v :g[u]) {
      if (!visited[v]){
        Dfs(v, put);
      }
    }
    st.push(u);
  } else {
    for (auto v : rg[u]) {
      if (!visited[v]) {
        Dfs(v);
      }
    }
  }
}

bool Kosaraju() {
  while (st.size()) st.pop();
  visited.assign(n, false);
  for (int i = 0; i < n; i++)
    if (!visited[i])
      Dfs(i, 1);

  visited.assign(n, false);
  int c = 0;
  while (st.size()){
    if (!visited[st.top()]) {
      c++, Dfs(st.top());
    }
    st.pop();
    if (c > 1) return false;
  }
  return c == 1;
}

      

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int a, b;
  int m;
  while (cin >> n >> m, n && m) {
    rep(i,0,2005) g[i].clear(), rg[i].clear();

    rep(i,0,m) {
      int p;
      cin >> a >> b >> p;
      a--, b--;
      g[a].push_back(b);
      rg[b].push_back(a);
      if (p == 2)
        g[b].push_back(a), rg[a].push_back(b);
    }

    cout << Kosaraju() << "\n";    
  }
}
