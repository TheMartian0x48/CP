// @author: the__martian

#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
vector<int> v;
int n, k;

long long solve(long long c, int i = 0) {
  if (i >= n) return 1e17;
  if (i == n - 1) {
    return abs(c - v[i]);
  }
  if (dp[i] == -1) {
    dp[i] = solve(v[i], i + 1);
    for (int j = 2; j <= k; j++) {
      dp[i] = min(dp[i], solve(v[i], i + j));
    }
  }
  return dp[i] + abs(c - v[i]);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  cin >> n >> k;
  dp.resize(n, -1);
  v.resize(n);
  for (auto &a : v) cin >> a;
  cout << solve(v[0]);
}
