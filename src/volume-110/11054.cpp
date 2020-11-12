// @author: the__martian
// 11054
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
  
  int n;
  vi v(100005);
  while (cin >> n, n) {
    rep(i,0,n) 
      cin >> v[i];
    
    ll res = 0, c = 0;
    for (int i = 0; i < n; i++) {
      res += abs(c);
      c += v[i];
    }
    cout << res << "\n";
  }
}
