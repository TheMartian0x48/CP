// author : the__martian
// 11548
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

vector<string> v(75);

int solve(int x, int y) {
  int res = 0;
  const string &str1 = v[x];
  const string &str2 = v[y];

  for (int i = 0; i < sz(str1); i++) {
    int tmp = 0;
    for (int j = 0, k = i; k < sz(str1) && j < sz(str2); k++, j++) {
      tmp += str2[j] == str1[k];
    }
    res = max(tmp, res);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  
  while (t--) {
    int n; cin >> n;
    rep(i,0,n)
      cin >> v[i];
    
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;        
        int tmp = solve(i, j);        
        res = max(res, tmp);
      }
    }
    cout << res << "\n";
  }
}
