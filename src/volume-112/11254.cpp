// @author: the__martian
// 11254

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

  ll n;
  while (cin >> n, n != -1) {
    n *= 2;
    int l = 0, r = 0;

    for(ll i = 1; i * i <= n; i++) {
      if (n % i || (i  + n / i - 1) % 2) continue;
      ll j = n / i;
      ll a = (i + j - 1) / 2;
      ll b = a - i;
      if (b >= 0 && a >= 0 && a - b > r - l) {
        l = b, r = a;
      }      
    }
    cout << n / 2 << " = " << l + 1 << " + ... + " << r << "\n";
  }
}