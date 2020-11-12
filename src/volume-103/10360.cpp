
// author: the__martian
// 10360
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
  
  vector<vector<ll>> v(1025, vector<ll>(1025));
  int t; cin >> t;
  while (t--){
    for (int i = 0; i < 1025; i++){
      for (int j = 0; j < 1025; j++){
        v[i][j] = 0;
      }
    }

    int d; cin >> d;
    int n, x, y; cin >> n;
    ll s;
    ll rx = 1025, ry = 1025, res = -1;
    for (int i = 0; i < n ; i++) {
      cin >> x >> y >> s;
      int ru = max(0, y - d), rd = min(1024, y + d);
      int cl = max(0, x - d), cr = min(1024, x + d);
      for (int r = ru; r <= rd; r++){
        for (int c = cl; c <= cr; c++){
          v[r][c] += s;
          if (v[r][c] > res) {
            res = v[r][c];
            rx = c;
            ry = r;
          } else if (v[r][c] == res) {
            if (c < rx || (c == rx && r < ry)) {
              rx = c;
              ry = r;
            }
          }
        }
      }
    }
    cout << rx << " " << ry << " " << res << endl;
  }
} 
