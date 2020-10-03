
// author: the__martian
// 10346
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll n, k; 
  while (cin >> n >> k) {
    ll butt = n;
    ll res = n;
    while (butt >= k) {
      res += butt / k;
      ll t = butt % k + butt / k;
      butt = t;
    }
    cout << res << "\n";
  }
}
