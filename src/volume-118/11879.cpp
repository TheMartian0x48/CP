// author : the__martian
// 11879 
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
    int d = 0;
    int f = 1;
    for (int i = sz(s) - 1; i >= 0; i--) {
      d += (s[i] - '0') * f;
      f *= 10;
      f %= 17;
      d %= 17;
    }
    cout << (d == 0) << "\n";
  }
}
