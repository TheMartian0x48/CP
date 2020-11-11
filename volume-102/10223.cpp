// author : the__martian
// 10223 
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


ll cnr(ll n, ll r) {
  ll res = 1;
  for (int i = r + 1; i <= n; i++) {
    res *= i;
    res /= (i - r);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vector<ll> v;
  ll last = 1, n = 1;
  while (last <= 4294967295LL) {
    last =  cnr(2*n, n) / (n + 1);
    v.push_back(last);
    n++;
  }
  while (cin >> n) {
    cout << (lower_bound(all(v), n) - v.begin() + 1) << "\n";
  }
}
