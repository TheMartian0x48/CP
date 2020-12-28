// @author: the__martian

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n), dp(n, 0);
  for (auto &a : v) cin >> a;
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = dp[i + 1] + abs(v[i] - v[i + 1]);
    if (i + 2 < n) {
      dp[i] = min(dp[i], dp[i + 2] + abs(v[i] - v[i + 2]));
    }
  }
  cout << dp[0];
}
