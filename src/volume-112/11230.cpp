// author : the__martian
// 11230
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

  int n, m, r, c;
  vector<vi> v(105, vi(105));
  while (cin >> n >> m >> r >> c, n && m && r && c) {
    rep(i,0,n) {
      string s; cin >> s;
      rep(j,0,m) {
        v[i][j] = s[j] - '0';
      }
    }

    int moves = 0;
    bool sol = true;
    for (int i = 0; sol && i < n; i++) {
      for (int j = 0; j < m && sol; j++) {
        if (v[i][j] == 0) continue;
        
        if (i + r - 1 >= n || j + c - 1 >= m) {
          sol = false;
          break;
        }
        moves++;
        for (int ii = i; ii  < i + r; ii++){
          for (int jj = j; jj < j + c; jj++) {
            v[ii][jj] = 1 - v[ii][jj];
          }
        }
      }
    }
    if (sol)        
      cout << moves << "\n";
    else 
      cout << -1 << "\n";
  }
}
