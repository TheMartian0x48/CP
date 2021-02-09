// @author: the__martian
// 10407
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

vi v(1005);
int n;
bool good(ll q) {
  ll d = (v[0] % q + q ) % q;
  for (int i = 0; i < n; i++) {
    ll r = (v[i] % q + q) % q;
    if (r != d) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  while (cin >> v[0], v[0]) {
    n = 1;
    while (cin >> v[n], v[n])n++;

    ll a = v[0], b;
    for (auto e : v)
      if (a != e) {b = e; break;}

    ll diff = abs(a - b);
    ll res = 1;
    for (ll i = 1; i * i <= diff; i++) {
      if (diff % i) continue;
      if (good(i)) 
        res = max(res, i);
      if (i * i != diff && good(diff / i))
        res = max(res, diff / i);
    }
    cout << res << "\n";
  }
}
