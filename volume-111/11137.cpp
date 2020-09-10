// @author: the__martian
// 11137


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

  int N = 10001;
  vector<vector<ll>> v(25, vector<ll>(N, 0));

  v[0][0] = 1;
  per (i, 21, 1) {
    v[i][0] = 1;
    rep (j, 1, N) {   
      v[i][j] = v[i+1][j];
      if (j - i * i * i >= 0) 
        v[i][j] += v[i][j - i * i * i];
    }
  }
  
  int n;
  while (cin >> n) {
    cout << v[1][n] << "\n";
  }
}