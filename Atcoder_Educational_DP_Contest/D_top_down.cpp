// @author: the__martian
// https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> w, v;
vector<vector<long long>> dp;

long long solve(int t, int i = 0) {
  if (i >= n || t <= 0) return 0;

  if (dp[i][t] != -1)
    return dp[i][t];
  // ignore
  dp[i][t] = solve(t, i + 1);
  // include
  if (t - w[i] >= 0) {
    dp[i][t] = max(dp[i][t], v[i] + solve(t - w[i], i + 1));
  }
  return dp[i][t];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> target;
  w.resize(n);
  v.resize(n);
  dp = vector<vector<long long>>(n, vector<long long>(target + 1, -1));
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  cout << solve(target);
}
