// @author: the__martian
// https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, target;
  cin >> n >> target;
  vector<int> w(n), v(n);
  vector<vector<long long>> dp(n + 1, vector<long long>(target + 2, 0));
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= target; j++) {
      dp[i][j] = max(dp[i][j], dp[i + 1][j]);
      if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], v[i] + dp[i + 1][j - w[i]]);
    }
  }
  cout << dp[0][target];
}
