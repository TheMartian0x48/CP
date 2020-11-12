// @author: the__martian
// 11723
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
  ll n, r, t = 1; 
  while (cin >> n >> r, n && r) {
    cout << "Case " << t++ << ": ";
    ll res  = n % r ? n / r + 1: n / r;
    res--;
    if (res > 26)
      cout << "impossible\n";
    else
      cout << res << "\n";
  }
}
