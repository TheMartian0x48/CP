/*
 * TheMartian0x48
 * USACO 2019 February Contest, Silver
 * Problem 3. The Great Revegetation
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);}
// clang-format 
int nmax = 1e5+5,n;
vector<vi> same(nmax), diff(nmax);
vector<bool> used(nmax);
vi color(nmax, -1);

bool dfs(int v, int c = 0) {
  used[v] = true;
  color[v] = c;
  for (auto u : same[v]) {
    if (used[u] && color[u] != color[v]) return false;
    else if (used[u] == false) dfs(u, c);
  }
  for (auto u : diff[v]) {
    if (used[u] && color[u] == color[v]) return false;
    else if (used[u] == false) dfs(u, 1 - c);
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("revegetate");

  int m; cin >> n >> m;
  char ch; int a, b;
  rep(i,0,m) {
    cin >> ch >> a >> b;
    if (ch == 'S') 
      same[a].push_back(b), same[b].push_back(a);
    else
     diff[a].push_back(b), diff[b].push_back(a);
  }
  
  int c = 0;
  rep(i,1,n+1) {
    if (used[i] == false) {
      int t = dfs(i);
      if (t) c++;
    }
  }
  if (c == 0) cout << 0;
  else {
    cout << 1 << string(c, '0');
  }
}
