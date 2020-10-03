
// author: the__martian
// 12482
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
  
  vector<string> v(1005);
  int n, l, c;
  while (cin >> n >> l >> c) {
    rep(i,0,n)
      cin >> v[i];
    int res = 1, line = 1;
    int len = v[0].size();
    rep(i,1,n) {
      if (len + 1 + sz(v[i]) <= c) {
          len += 1 + sz(v[i]);
      } else {
        len = sz(v[i]);
        line++;
        if (line == l + 1){
          res++;
          line = 1;
        }
      }
    }
    cout << res << "\n";
  }
} 
