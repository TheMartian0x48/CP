/*
 * TheMartian0x48
 * UVa 10973
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
// clang-format on

vector<vi> g(3001);
vector<bitset<3001>> st(3001);

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  rep(i,1,n+1) g[i].clear(), st[i].reset();
  int a, b;
  rep(i,0,m) {
    scanf("%d%d", &a, &b);
    st[a].set(b);
    st[b].set(a);
    if (a > b)  g[b].push_back(a);
    else g[a].push_back(b);
  }
  ll res = 0;
  rep(i,1,n - 1) {
    rep(j,0,sz(g[i])) {
      rep(k,j + 1, sz(g[i])) {
        if (st[g[i][j]][g[i][k]]) res++;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  // int testcase = 1;
  scanf("%d", &test);
  while (test--) {
    // cout << "Case #" << testcase++ << ": ";
    solve();
  }
}
