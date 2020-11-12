
// author: the__martian
// 12498
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

  vector<vi> v(55, vi(55));

  int t; cin >> t;
  rep(test, 1, t + 1){
    cout << "Case " << test << ": ";
    int r, c; cin >> r >> c;
    rep(i,0,r){
      string s; cin >> s;
      rep(j,0,c){
        v[i][j] = s[j] - '0';
      }
    }
    int res = INT_MAX;
    rep(j,0,c){
      int tmp = 0;
      rep(i,0,r){
        if (v[i][j] == 0)
          continue;
        bool suc = false;
        int k = j - 1, tmp2 = 55;
        while (k >= 0 && v[i][k])
          k--;
        if (k >= 0){
          suc = true;
          tmp2 = j - k;
        }
        k = j + 1;
        while (k < c && v[i][k])
          k++;
        if (k < c) {
          suc = true;
          tmp2 = min(tmp2, k - j);
        }
        if (suc == false) {
          tmp = INT_MAX;
          break; 
        } else {
          tmp += tmp2;
        }
      }
      res = min(res, tmp);
    }
    if (res == INT_MAX)
      res = -1;
    cout << res << "\n";
  }
}
