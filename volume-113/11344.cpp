// @author: the__martian
// 11344
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
  
  ll t; cin >> t;
  vector<ll> v(15);
  while (t--) {
    string n; cin >> n;
    int m; cin >> m;
    for(int i = 0; i < m; i++)  
      cin >> v[i];
    
    int sol = true;
    for (int i = 0; i < m && sol; i++) {
      ll q  = 0, f = 1;
      for (int j = sz(n) - 1; j >= 0; j--) {
        q = q + (f * (n[j] - '0')) % v[i];
        q %= v[i];
        f = (f * 10) % v[i];
      }
      sol = q == 0;
    }
    cout << n << (sol ? " - Wonderful." : " - Simple.") << "\n";
  }
}
