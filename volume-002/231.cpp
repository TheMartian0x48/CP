// @author: the__martian
// 231

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

  int n, tt = 1;
  bool first = true;
  vi v(100000), dp(100000);
  while (true) {
    int i = -1;
    cin >> v[++i]; 
    if (v[i] == -1) break;
    if (!first) cout << "\n";

    first = false;
    cout << "Test #"<< tt++ <<":\n  maximum possible interceptions: ";

    int res = 1;
    dp[0] = 1;

    while (cin >> n, n != -1) {
      v[++i] = n;
      int tmp = 0;
      rep(j,0,i) {
        if (v[j] >= v[i])
          tmp = max(tmp, dp[j]);
      }
      dp[i] = tmp + 1;
      res = max(res, dp[i]);
    }
    cout << res << "\n";
  }
}
