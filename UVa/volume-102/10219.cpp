// @author: the__martian
// 10219
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

  ll n, k; 
  while (cin >> n >> k) {
    double a = 0, b = 0;
    k = min(k, n - k);
    rep(i,1,k + 1) {
      a += log10(n - i + 1);
      b += log10(i);
    }
    ll res = a - b;
    res += 1;
    cout << res << "\n";
  }
}
