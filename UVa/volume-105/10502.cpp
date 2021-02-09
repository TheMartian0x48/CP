// author : the__martian
// 10502
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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vector<vi> v(101, vi(101));
  int n, m;
  while (cin >> n >> m, n && m) {
    rep(i,0,n) {
      string s; cin >> s;
      rep(j,0,m) {
        v[i][j] = s[j] - '0';
      }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 0) continue;
        for (int x = i, l = -1; x >= 0 && v[x][j]; x--) {
          for (int y = j; y > l; y--) {
            if (v[x][y] == 0) {
              l = y;
              break;
            }
            res++;
          }
        }        
      }
    }
    cout << res << "\n";
  }
}
