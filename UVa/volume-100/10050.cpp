
// author: the__martian
// 10050
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

  vi v(4000);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    n++;
    v.assign(n, 0);
    int p; cin >> p;
    rep(i,0,p){
      int x; cin >> x;
      int j = x;
      while (j < n){
        v[j] = 1;
        j += x;
      }
    }
    int res = 0;
    rep(i,0,n) {
      if (i % 7 != 0 && i % 7 != 6)
        res += v[i];
    }
    cout << res << "\n";
  }
}
