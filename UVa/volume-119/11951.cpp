// @author: the__martian
// 11951

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

int v[105][105];

void solve() {
  int n, m; cin >> n >> m;
  ll K, area = 0, p = 0; 
  cin >> K;

  rep(i,0,n) {
    rep(j,0,m) {
      cin >> v[i][j];
      if (i - 1 >= 0)
        v[i][j] += v[i - 1][j];
      if (j - 1 >= 0)
        v[i][j] += v[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        v[i][j] -= v[i - 1][j - 1];
    }
  }

  rep(i,0,n) {
    rep(j,0,m) {
      rep(k,i,n) {
        rep(l,j,m) {
          ll a = (k - i + 1) * (l - j + 1);
          ll tmp = v[k][l];
          if (i - 1 >= 0)
            tmp -= v[i - 1][l];
          if (j - 1 >= 0)
            tmp -= v[k][j - 1];
          if (i - 1 >= 0 && j - 1 >= 0)
            tmp += v[i - 1][j - 1];
          
          if (a > area && tmp <= K)
            area = a, p = tmp;
          else if (a == area)
            p = min(p, tmp);
        }
      }
    }
  }
  cout << area << " " << p << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}