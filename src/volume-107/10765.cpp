
// author: the__martian
// 10765
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

vector<vi> g(10005);
vector<bool> vis(10005);
vi in(10005), low(10005);
vector<pii>cc(10005);
int n, m, timer;

void dfs(int u = 0, int p = -1) {
  vis[u] = true;
  in[u] = low[u] = timer++;
  int child = 0;
  for (auto v : g[u]){
    if (v == p) continue;
    if (vis[v]){
      low[u] = min(low[u], in[v]);
    } else {
      child++;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= in[u] && p != -1){
        cc[u].second++;
      }
    }
  }
  if(p == -1){
    cc[u].second = child;
  } else {
    cc[u].second++;
  }
}

void solve(){
  rep(i,0,n)
    vis[i] = false, in[i] = 0, low[i] = 0, cc[i] = {i, 0};
  timer = 1;
  dfs();
}

bool cmp(pii &a, pii &b){
  return a.second < b.second || (a.second == b.second && a.first > b.first);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  while (cin >> n >> m, n && m){
    int u, v;
    while (cin >> u >> v, u != -1){
      g[u].push_back(v);
      g[v].push_back(u);
    }
    solve();
    rep(i,0,m){
      make_heap(cc.begin() + i, cc.begin() + n, cmp);
      cout << cc[i].first << " " << cc[i].second << "\n";
    }
    rep(i,0,10005){
      g[i].clear();
    }
    cout << "\n";
  }
}
