// @author: the__martian
// 991
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
  
  vector<ll> fac(25,1);
  rep(i,1,21) {
    fac[i] = i * fac[i - 1];
  }

  int n;
  bool first = true;
  while (cin >> n) {
    if (!first) cout << "\n";
    first = false;
    ll res = fac[2 * n] / fac[n] / fac[n] / (n + 1);
    cout << res << "\n";
  }  
}