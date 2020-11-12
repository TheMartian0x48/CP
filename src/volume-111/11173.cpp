
// author : the__martian
// 11173
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

ll solve(int n, int k) {
  ll p = 1 << n;
  ll res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (k >= p / 2) {
      res += 1 << i;
    }
    k = min(k * 1LL, p - 1 - k);
    p /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
}