// @author: the__martian
// 264
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


vector<ll> v(10000);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  rep(i,1,10000) {
    v[i] = i + v[i - 1];
  }

  int n;
  while (cin >> n) {
    ll i = lower_bound(all(v), n) - v.begin();
    int pos = n - v[i - 1];
    if (i & 1)
      cout << "TERM " << n << " IS " << i - pos + 1 << "/" << pos << "\n";
    else 
      cout << "TERM " << n << " IS " << pos << "/" << i - pos + 1<< "\n";
  }
}