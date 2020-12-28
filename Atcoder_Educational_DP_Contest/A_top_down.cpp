// @author: the__martian

#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

long long solve(vector<int> &a, long long c, int i = 0) {
  if (i >= (int)a.size()) {
    return 1e15;
  } else if (i == (int)a.size() - 1) {
    return abs(a[i] - c);
  }
  if (dp[i] == -1) {
    dp[i] = min(solve(a, a[i], i + 1), solve(a, a[i], i + 2));
  }
  return dp[i] + abs(c - a[i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  dp.resize(n, -1);
  vector<int> v(n);
  for (auto &a : v) cin >> a;
  cout << solve(v, v[0]);
}
