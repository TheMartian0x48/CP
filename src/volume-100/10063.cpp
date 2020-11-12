// @author: the__martian
// 10063
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

string s;
void solve(string res = "", int idx = 0) {
  if (res.size() == s.size()) {
    cout << res << "\n";
    return;
  }
  for (int i = 0; i <= res.size(); i++) {
    if (i == 0) {
      solve(s[idx] + res, idx + 1);
    } else {
      string t = res.substr(0,i) + s[idx] + res.substr(i,10);
      solve(t, idx + 1);
    }
  }
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  bool first = true;
  while (cin >> s) {
    if (!first) cout << "\n";
    first = false;
    solve();
  }
}