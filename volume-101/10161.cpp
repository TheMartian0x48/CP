// @author: the__martian
// 10161
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
  while (cin >> n, n){
    ll r = 0;
    while ((ll)pow(r + 1, 2) < n) r++;
    ll d = n - r * r;
    if (d == r + 1)
      cout << r + 1 << " " << r + 1 << "\n";
    else if (d < r + 1) {
      if (r % 2) {
          cout << d << " " << r + 1 << "\n";
      } else {
          cout << r + 1 << " " << d << "\n";
      }
    } else {
      if (r % 2) {
          cout << r + 1 << " " << 2 * r + 2 - d << "\n";      
      } else {
          cout << 2 * r + 2 - d << " " << r + 1 << "\n";
      }
    }
  }
}
