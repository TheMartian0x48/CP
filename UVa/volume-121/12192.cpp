// author : the__martian
// 12192 
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

int n, m, lb, ub;
vector<vi> v(500, vi(500));

bool good(int r, int c, int ec) {
  int nr = r + ec - c;
  if (nr >= n) return false;
  return v[nr][c] <= ub && v[nr][ec] <= ub;
  return false;
}

int solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int lc = lower_bound(v[i].begin(), v[i].begin() + m, lb) - v[i].begin();
    if (lc == m || v[i][lc] > ub)
      continue;
    int rc = upper_bound(v[i].begin(), v[i].begin() + m, ub) - v[i].begin();
    int l = lc, r = rc;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (good(i, lc, mid))
        l = mid;
      else 
        r = mid;
    }
    res = max(res, r - lc);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> n >> m, n && m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cin >> v[i][j];
    }
    int q; cin >> q;
    while (q--) {
      cin >> lb >> ub;
      cout << solve() << '\n';
    }
    cout << "-\n";
  }
}
