// @author: the__martian
// 11059
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

  vector<ll> v(20);
  int n, tt = 1; 
  while (cin >> n) {
    ll res = -1e18;
    rep(i,0,n) {
      cin >> v[i];
    }
    rep(i,0,n) {
      ll tmp = 1;
      for (int j = i; j >= 0; j--) {
        tmp *= v[j];
        res = max(res, tmp);
      }
    }
    res = max(res, 0LL);
    cout << "Case #"<< tt++ << ": The maximum product is "<< res << ".\n\n";
  }
}