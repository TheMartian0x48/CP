// @author: the__martian
// 11875

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

  ll t;
  cin >> t;
  vi v(100);
  rep(i,1,t+1) {
    int n; cin >> n;
    rep(j,0,n)
      cin >> v[j];
    cout << "Case " << i << ": ";
    cout << v[n/2] << "\n";

  }
}