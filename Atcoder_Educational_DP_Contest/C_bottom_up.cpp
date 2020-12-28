// @author: the__martian

#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(3, -1));
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  for (int i = 1; i < n; i++) {
    v[i][0] +=  max(v[i - 1][1], v[i - 1][2]);
    v[i][1] +=  max(v[i - 1][0], v[i - 1][2]);
    v[i][2] +=  max(v[i - 1][0], v[i - 1][1]);
  }
  int res = 0;
  for (int i = 0; i < 3; i++) {
    res = max(res, v[n - 1][i]);
  }
  cout << res;
}
