// author : the__martian
// 11631
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

struct DSU{
  int size;
  vi p, s;
  DSU(int n) {
    reset(n);
  }
  void reset(int n) {
    size = n;
    p.resize(n), s.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }
  int find(int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (s[a] > s[b]) {
      s[a] += s[b];
      p[b] = a;
    } else {
      s[b] = s[a];
      p[a] = b;
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  DSU dsu(1);
  int n, m;
  vector<pair<int, pii>> g(200005);
  while (cin >> n >> m, n != 0 && m != 0) {
    dsu.reset(n);
    ll mx = 0;
    int u, v, w;
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      g[i] = {w, {u, v}};
      mx += w;
    }
    sort(g.begin(), g.begin() + m);
    ll mi = 0;
    for (int i = 0; i < m; i++) {
      int a = dsu.find(g[i].second.first);
      int b = dsu.find(g[i].second.second);
      w = g[i].first;
      if (a != b) {
        dsu.merge(a, b);
        mi += w;
      }
    }
    cout << mx - mi << "\n";
  }

}
