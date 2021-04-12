/*
 * TheMartian0x48
 * UVa 868
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
int n, m;
vector<vector<int>> v(500, vi(500));
pii start  = {INT_MAX, INT_MAX}, finish = {INT_MAX, INT_MAX}, f;
vi dr{-1, 0, 0, 1}, dc{0, -1, 1, 0};
bool found;

void cs(int r, int c, int t = 1, int s = 1) {
  if (c < 0 || c >= m || r < 0 || r >= n || v[r][c] != t) return;
  if (r == n - 1 && finish > pii(n - 1, c)){
    start = f;
    finish = {n - 1, c};
    found = true;
  }
  if (r == n - 1) return;

  int save = v[r][c];  v[r][c] = -1;

  if (t == s) s++, t = 1; else t++;

  for (int i = 0; i < 4; i++) {
    cs(r + dr[i], c + dc[i], t, s);
  }

  v[r][c] = save;
}

void solve() {
  cin >> n >> m;
  rep(i,0,n) {
    rep(j,0,m) {
      cin >> v[i][j];
    }
  }
  found = false;
  start  = {INT_MAX, INT_MAX}, finish = {INT_MAX, INT_MAX};
  rep(j, 0, m) {
    if (v[0][j] == 1){
      f = {0, j}, cs(0, j);
      if (found) break;
    }
  }
  cout << start.first + 1<< " " << start.second + 1 << "\n";
  cout << finish.first + 1 << " " << finish.second + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  // int testcase = 1;
  cin >> test;
  while (test--) {
    // cout << "Case #" << testcase++ << ": ";
    solve();
    if (test) cout << "\n";
  }
}
