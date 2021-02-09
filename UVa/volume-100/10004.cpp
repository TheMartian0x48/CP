// author : the__martian
// 10004
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

vector<vi> g(205);
int n;
vi color(205);

string bfs() {
  color.assign(n, -1) ;
  queue<int> q;
  q.push(0);
  color[0] = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (auto v : g[u]) {
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if(color[v] == color[u]) {
        return "NOT BICOLORABLE.\n";
      }
    }
  }
  return "BICOLORABLE.\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);


  while (cin >> n, n) {
    int l; cin >> l;
    int u, v;
    while (l--) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << bfs();
    for (int i = 0; i < 205; i++)
      g[i].clear();
  }
}
