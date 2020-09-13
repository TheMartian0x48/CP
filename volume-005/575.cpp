// @author: the__martian
// 575
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
  
  string s;
  while (cin >> s, s != "0") {
    ll res = 0;


    for (ll i = sz(s) - 1, p = 2; i >= 0; i--) {
      res += (p - 1) * (s[i] - '0');
      p *= 2;
    }
    cout << res << "\n";
  }
}