// @author: the__martian
// 11567
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

unordered_map<ll, ll> mp;

ll solve(ll n) {
  if (n == 0) {
    return 0;
  } else if (!(n & (n - 1))) {
    return  1 + log2(n);
  } 
  
  if (n & 1) {
    return 1 + min(solve(n -1 ), solve(n + 1));
  }

  return 1 + solve(n / 2);  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll n; 
  while (cin >> n) {
    cout << solve(n) << "\n";
  }
}