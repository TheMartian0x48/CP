// author : the__martian
// 924
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

vector<vi> g(2505);
vector<bool> vis(2005);
vi dis(2005);
int n, mx_size =  0, first_day = 0;

void bfs(int s) {
  vis.assign(n, false);
  queue<int> q, qt;
  q.push(s);
  vis[s] = true;
  dis[s] = 0;
  bool first = true;
  int i = 0;
  while (q.size()) {
    if (!first) {
      if (mx_size < sz(q)) {
        mx_size = sz(q);
        first_day = i;
      }
    }
    first = false;
    while (q.size()) {
      int u = q.front(); q.pop();
      for (auto v : g[u]) {
        if (vis[v] == false) {
          qt.push(v);
          vis[v] = true;
        }
      }
    }
    while (qt.size()) {
      q.push(qt.front());
      qt.pop();
    }
    i++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);


  cin >> n;
  for (int i = 0; i < n; i++){
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      int t; cin >> t;
      g[i].push_back(t);
    }
  }
  int t; cin >> t;
  while (t--) {
    first_day = 0;
    mx_size = 0;
    int u; cin >> u;
    bfs(u);
    if (mx_size == 0)
      cout << 0 << "\n";
    else 
      cout << mx_size << " " << first_day << "\n";
  }
}
