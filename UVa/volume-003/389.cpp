// author : the__martian
// 389
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  int b1, b2;
  while (cin >> s >> b1 >> b2) {
    ll n = 0, f = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] >= 'A' && s[i] <= 'Z')
        n += (s[i] - 'A' + 10) * f;
      else
        n += (s[i] - '0') * f;
      f *= b1;
    }
    string res;
    if(!n)
      res = "0";
    while (n) {
      int r = n % b2;
      if (r < 10)
        res += '0' + r;
      else
        res += 'A' + r - 10;
      n /= b2;
    }
    
    reverse(all(res));
    if (res.size() < 7)
      res = string(7 - res.size(), ' ') + res;
    else if (res.size() > 7)
      res = "  ERROR";
    cout << res << "\n";
  }
}
