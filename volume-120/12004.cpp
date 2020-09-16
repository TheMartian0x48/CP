// @author: the__martian
// 12004
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
  
  ll t, i = 0; cin >> t;
  while (t--) {
    cout << "Case " << ++i << ": ";
    ll n; cin >> n;
    n *= (n - 1);
    n /= 2;
    if (n % 2)
      cout << n << "/2\n";
    else
      cout << n / 2 << "\n";
  }
}