// author : the__martian
// 701 
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


bool good(double y, string str) {
  ll s = pow(10, y);
  return str == to_string(s);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string n;
  while (cin >> n) {
    int len = sz(n);
    int i = 2;
    bool sol = false;
    int res;
    int bound = 6e6;
    while (i < bound) {
      double y = i * log10(2);
      int tmp = y + 1;
      y -= tmp - len;
      if (tmp > 2 * len && good(y, n)) {
        res = i;
        sol = true;
        break;
      }
      i++;
    }
    if (sol)
      cout << res << "\n";
    else 
      cout << "no power of 2\n";
  }
}
