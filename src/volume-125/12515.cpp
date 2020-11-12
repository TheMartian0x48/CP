
// author: the__martian
// 12515
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

  int n, m; cin >> n >> m;
  vector<string> v(n);
  rep(i,0,n)
    cin >> v[i];

  while(m--){
    string s; cin >> s;
    int idx = 0, hd = -1;

    rep(i,0,n){
      if (sz(s) > sz(v[i]))
          continue;

      int h = 0; 
      for (int j = 0; j + sz(s) <= sz(v[i]); j++) {
        int tmp = 0;
        for (int k = 0; k < sz(s); k++){
          tmp += s[k] == v[i][j + k];
        }
        h = max(h, tmp);
      }

      if (h > hd)
        hd = h, idx = i;
    }
    cout << idx + 1<< "\n";

  }
} 
