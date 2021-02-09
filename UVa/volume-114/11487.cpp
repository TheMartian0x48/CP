// author : the__martian
// 11487
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

vector<string> g(11);
vector<vector<int>> vis(11, vi(11)), dis(11, vi(11)), pa(11, vi(11));
int n, dist, path, mod = 20437;
vi dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};

bool Valid(int r, int c, pii &t) {
  if (r < 0 || c < 0 || r >= n || c >= n || g[r][c] == '#' || !(g[r][c] == '.' || pii(r, c) == t))
    return false;
  return true;
}

void bfs(pii &source, pii & tar) {
  for (int i =  0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vis[i][j] = 0, dis[i][j] = INT_MAX, pa[i][j] = 0;
    }
  }
  queue<pii> q;
  q.push(source);
  vis[source.first][source.second] = 1;
  dis[source.first][source.second] = 0;
  pa[source.first][source.second] = 1;
  while (q.size()) {
    int s = q.size();
    while (s--) {
      auto p = q.front(); q.pop();
      for (int i = 0; i < 4; i++) {
        int r = p.first + dr[i];
        int c = p.second + dc[i];
        if (!Valid(r, c, tar)) continue;
        if (dis[r][c] > 1 + dis[p.first][p.second]) {
          dis[r][c] = 1 + dis[p.first][p.second];
          pa[r][c] = pa[p.first][p.second];
        } else if (dis[r][c] == dis[p.first][p.second] + 1) {
          pa[r][c] += pa[p.first][p.second];
        }
        if (vis[r][c] == 0) {
          q.push({r, c});
          vis[r][c] = 1;
        }
      }
    }
    if (vis[tar.first][tar.second]) {
      g[source.first][source.second] = '.';
      dist += dis[tar.first][tar.second];
      path *= pa[tar.first][tar.second];
      path %= mod;
      return;
    }
  }
  path = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test = 1;
  while (cin >> n, n) {
    vector<pair<char, pii>> v;
    for (int i = 0; i < n;  i++)
      cin >> g[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0;j < n; j++) {
        if (g[i][j] != '.' && g[i][j] != '#')
          v.push_back({g[i][j], {i, j}});
      }
    }
    sort(all(v));
    path = 1;
    dist = 0;
    int len = v.size();
    for (int i = 0; i < len - 1; i++) {
      bfs(v[i].second, v[i + 1].second);
      if (path == 0)
        break;
    }
    cout << "Case " << test++ << ": ";
    if (path) {
      cout << dist << " " << path << "\n";
    } else {
      cout << "Impossible\n";
    }
  } 
}

