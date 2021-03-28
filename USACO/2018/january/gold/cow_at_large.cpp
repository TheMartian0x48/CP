
/*
 * TheMartian0x48
 * USACO 2018 January Contest, Gold
 * Problem 2. Cow at Large
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on

vector<vi> g;
int n;
queue<int> q;
vi dis;
void bfs() {
  while (q.size()) {
    int u = q.front();
    q.pop();
    for(auto a : g[u]) {
      if (dis[a] > 1 + dis[u]) {
        dis[a] = 1 + dis[u];
        q.push(a);
      }
    }
  }
}

int dfs(int s, int p = - 1, int l = 0) {
   if ( dis[s] <= l) return 1;
   int r = 0;
   for (auto a : g[s]) {
     if (a != p) {
      r += dfs(a, s, l + 1);
     }
   }
   return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("atlarge");

  cin >> n; int k; cin >> k;
  g.resize(n + 1);
  dis.resize(n + 1, INT_MAX);
  int a, b; 
  rep(i,0,n-1) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rep(i,1,n+1) {
    if (g[i].size() == 1) {
      dis[i] = 0;
      q.push(i);
    }
  }
  bfs();
  cout << dfs(k);
}
