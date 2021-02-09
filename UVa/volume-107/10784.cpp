// @author: the__martian
// 10784
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

vector<ll> prime;
vector<pair<ll,ll>> twin;


bool inline good(ll n, ll N) {
  return (n * n - 3 * n) / 2 >= N;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll tt = 1;
  ll n;
  while (cin >> n, n) {
    ll l = 3, r = 1e8;

    while (l + 1 < r) {
      ll m = (r - l) / 2 + l;
      if (good(m, n))
        r = m;
      else
        l = m;
    } 
    cout << "Case " << tt++ << ": " << r << '\n';
  }
}