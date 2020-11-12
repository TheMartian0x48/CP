
// author: the__martian
// 10773
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
  int tt; cin >> tt;
  rep(i,0,tt){
    printf("Case %d: ", i + 1);
    ll n, v, u; cin >> n >> v >> u;
    if (v >= u || u == 0 || v == 0) {
      printf("can't determine\n");
    } else {
      double t = n * abs((u - sqrt(u * u - v * v)) / (1.0 * u * sqrt(u * u - v * v)));
      printf("%.3lf\n", t);
    }
  }
}
