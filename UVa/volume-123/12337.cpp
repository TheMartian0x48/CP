/*
 * TheMartian0x48
 * UVa 12337
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

vi dr{0, 1, 0, -1}, dc{1, 0, -1, 0};
vector<vector<char>> v(105, vector<char>(105));
void solve() {
 string s; cin >> s;
 int n = sz(s), res = INT_MAX;
 for (int i = 2; i <= (int)sqrt(n); i++) {
  if (n % i) continue;
  for (auto p : vector<pii>{pii(i, n / i), pii(n / i, i)}) {
    int r = p.first, c = p.second;
    int k = 0, dir = 0;
    int ii = 0, jj = 0;
    rep(l, 0, r) v[l].assign(c, '.');
    while (k < n) {
      v[ii][jj] = s[k++];
      int tr = ii + dr[dir], tc = jj + dc[dir];
      if (tr == r || tc == c || tr < 0 || tc < 0 || v[tr][tc] != '.')
        dir = (dir + 1) % 4;
      ii = ii + dr[dir];
      jj = jj + dc[dir];
    }
    bool beautiful = true;
    for (int tc = 0; tc < c; tc++) {
      for (int tr = 1; tr < r; tr++) {
        if (v[tr][tc] != v[0][tc]) {
          beautiful = false;
          break;
        }
      }
      if (beautiful == false) break;
    }
    if (beautiful) res = min(res, r + c);
  }
 }
 if (res == INT_MAX) res = -1;
 cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  int testcase = 1;
  cin >> test;
  while (test--) {
    cout << "Case " << testcase++ << ": ";
    solve();
  }
}
