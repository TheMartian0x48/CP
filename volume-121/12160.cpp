
// author : the__martian
// 12160
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

vi dis(10000), button(10), vis(10000);
int L, U, r;

int bfs(int s) {
  dis[s] = 0;
  vis.assign(10000, -1);
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < r; i++){
      int v = (u + button[i]) % 10000;
      if (vis[v] == -1) {
        if (v == U) return 1 + dis[u];
        dis[v] = 1 + dis[u];
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test = 1;
  while (cin >> L >> U >> r){
    if (L == 0 && U == 0 && r == 0)
      break;
    cout << "Case " << test++ << ": ";
    for (int i = 0; i < r; i++)
      cin >> button[i];
    int times = bfs(L);
    if (times == -1) {
      cout << "Permanently Locked\n";
    } else {
      cout << times << "\n";
    }
  }  
}