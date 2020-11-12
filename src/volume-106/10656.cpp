// @author: the__martian
// 10656
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n;
  vector<ll> v(1005);
  while (cin >> n, n) {
    rep(i,0,n) {
      cin >> v[i];
    }
    bool f = true;
    rep(i,0,n) {
      if (!v[i]) continue;
      if (!f) cout <<  " ";
      f = false;
      cout << v[i];
    }
    if (f) cout << 0;
    cout <<  endl;
  }
}