// author : the__martian
// 10551 
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

  int n;
  while (cin >> n, n){
    string p, q; cin >> p >> q;
    ll m = 0, f = 1;
    for (int i = sz(q) - 1; i >= 0; i--) {
      m += (q[i] - '0') * f;
      f *= n;
    }
    ll res = 0;
    f = 1;
    for (int i = sz(p) - 1; i >= 0; i--) {
      res += (p[i] - '0') * f;
      res %= m;
      f = (f * n) % m;
    }
    p = res == 0 ? "0" : "";
    while (res) {
      p += (res % n) + '0';
      res /= n;
    }
    reverse(all(p));
    cout << p << "\n";
  }
}
