// @author: the__martian
// 836

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


int v[30][30];

void solve() {
  string s; cin >> s;
  int n = s.size();
  rep(i,0,n) {
    rep(j,0,n) {
      v[i][j] = s[j] - '0';

      if (i - 1 >= 0) v[i][j] += v[i - 1][j];
      if (j - 1 >= 0) v[i][j] += v[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0) v[i][j] -= v[i - 1][j - 1];
    }
    if (i != n - 1) cin >> s;
  }

  int res = 0;
  rep(i,0,n) {
    rep(j,0,n) {
      rep(k,i,n) {
        rep(l,j,n) {
          int tmp = v[k][l];
          if (i - 1 >= 0)
            tmp -= v[i - 1][l];
          if (j - 1 >= 0)
            tmp -= v[k][j - 1];
          if (i - 1 >= 0 && j - 1 >= 0)
            tmp += v[i - 1][j - 1];
          
          if (tmp == (k - i + 1) * (l - j + 1) && tmp > res)
            res = tmp;
        }
      }
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    solve();
    if (t) cout <<"\n";
  }
}