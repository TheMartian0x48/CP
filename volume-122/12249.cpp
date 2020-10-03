
// author: the__martian
// 12249
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

string merge(string a, string b){
  for (int i = sz(b) - 1; i >= 0; i--){
    bool flag = true;
    int j,k;
    for ( j = i, k = sz(a) - 1; j >= 0 && k >= 0; j--, k--) {
      if (b[j] != a[k]){
        flag = false;
        break;
      }
    }
    if (flag && j == -1){
      for (j = i + 1; j < sz(b); j++)
        a += b[j];
      return a;
    }
  }
  return a + b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int t, tt = 1; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<string> v(n);
    vi p(n);
    rep(i,0,n)
      cin >> v[i], p[i] = i;
    
    int res = 10000;
    do {
      string s = v[p[0]];
      for (int i = 1; i < n; i++) {
        s = merge(s, v[p[i]]);
      }
      res = min(res, sz(s));
    } while (next_permutation(all(p)));
    cout << "Case " << tt++ << ": " << res << "\n";
  }
} 
