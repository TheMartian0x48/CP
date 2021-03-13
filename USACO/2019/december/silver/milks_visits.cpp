/*
 * TheMartian0x48 
 * USACO 2019 December Contest, Silver
 * Problem 3. Milk Visits
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
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);

  int n, m; cin >> n >> m;
  string cow; cin >> cow;
  vector<vector<int>> g(n + 1);
  int a, b;
  rep(i,0,n - 1) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi cc(n + 1, 0);
  
  for (int i = 1; i <= n; i++) {
    if (cc[i] == 0) {
      queue<int> q;
      q.push(i);
      cc[i] = i;
      while (q.size()) {
        a = q.front(); q.pop();
        for (auto b : g[a]) {
          if (cc[b] == 0 && cow[a - 1] == cow[b - 1]) {
            q.push(b);
            cc[b] = i;
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    char ch; cin >> ch;
    if (cc[a] == cc[b] && cow[a - 1] != ch) cout << 0;
    else cout << 1;
  }  
}
