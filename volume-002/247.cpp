// @author: the__martian
// 247
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

unordered_map<string, int> id;
unordered_map<int, string> name;
int n, e;
vector<vi> g(30), gr(30);
vi visited;
stack<int> st;
bool first;

void dfs(int u, int t = 1) {
  if(t == 1) {
    visited[u] = 1;
    for (auto v :  g[u]) {
      if (visited[v] == 0) {
        dfs(v);
      }
    }
    st.push(u);
  } else {
    if (!first)
      cout << ", ";
    first = false;
    visited[u] = 1;
    cout << name[u];
    for (auto v : gr[u]) {
      if (visited[v] ==0) {
        dfs(v, 2);
      }
    }
  }
}

void Kosaraju() {
  while (st.size())
    st.pop();
  visited.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0)
      dfs(i);
  }
  visited.assign(n, 0);
  while (st.size()){
    if (visited[st.top()] == 0) {
      first = true;
      dfs(st.top(), 2);
      cout << "\n";
    }
    st.pop();
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int tt = 1;
  bool First = true;
  while (cin >> n >> e, n || e) {
    if (!First)
        cout << "\n";
    First = false;
    rep(i,0,e) {
      string u, v; cin >> u >> v;
      int a, b;
      if (id.find(u) == id.end()){
        id[u] = id.size();
        name[id[u]] = u;
      }
      if (id.find(v) == id.end()){
        id[v] = id.size();
        name[id[v]] = v;
      }
      a = id[u];
      b = id[v];
      g[a].push_back(b);
      gr[b].push_back(a);
    }
    cout << "Calling circles for data set " << tt++ << ":\n";
    if (e)
    Kosaraju();
    rep(i,0,30)
      g[i].clear(), gr[i].clear();
    id.clear(), name.clear();
  }
}
