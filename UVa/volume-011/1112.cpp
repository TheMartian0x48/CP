
// author: the__martian
// 1112
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

vector<vector<pii>> g(105);
int n, t, e, INF = 1e9, res;
vi dis(105);

void distance(int s){

  dis.assign(n, INF);
  dis[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  while (pq.size()){
    int u = pq.top().second;
    int w = pq.top().first;
    pq.pop();

    if (w != dis[u]) continue;

    for (auto p : g[u]){
      int v = p.first;
      int ww = p.second;
      if (dis[u] + ww < dis[v]){
        dis[v] = dis[u] + ww;
        pq.push({dis[v], v});
      }
    }
  }
  res += dis[e] <= t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int tt; cin >> tt;
  while(tt--){
    cin >> n >> e >> t;
    e--;
    int m, u, v, ti; cin >> m;
    while (m--){
      cin >> u >> v >> ti;
      g[u - 1].push_back({v - 1, ti});
    }

    for (int i = 0; i < n; i++)
      distance(i);
    cout << res << "\n";
    for (int i = 0; i < 105; i++)
      g[i].clear();
    res = 0;
    if (tt)
      cout << "\n";
  }

} 
