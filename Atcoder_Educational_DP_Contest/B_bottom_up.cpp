// @author: the__martian

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> dp(n, 0), v(n);
  for (auto &a : v) cin >> a;
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = dp[i + 1] + abs(v[i] - v[i + 1]);
    for (int j = 2; j <= k && i + j < n; j++) {
      dp[i] = min(dp[i], dp[i + j] + abs(v[i] - v[i + j]));
    }
  }
  cout << dp[0];
}
