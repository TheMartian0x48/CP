// @author: the__martian
// 11456
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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n), lis(n), lds(n);
    rep(i,0,n) 
      cin >> v[i];
    
    per(i,n - 1, 0) {
      int mx = 0;
      rep(j,i + 1, n) {
        if (v[j] < v[i]) {
          mx = max(mx, lis[j]);
        }
      }
      lis[i] = mx + 1;
    }

    per(i,n - 1, 0) {
      int mx = 0;
      rep(j,i + 1, n) {
        if (v[j] > v[i]) {
          mx = max(mx, lds[j]);
        }
      }
      lds[i] = mx + 1;
    }
    
    int res = 0;
    rep(i,0,n) {
      res = max(res, lis[i] + lds[i] - 1);
    }
  
    cout << res << "\n";
  }
}