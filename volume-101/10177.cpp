// @author: the__martian
// 10177
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

  ll n;
  while (cin >> n) {
    ll s2 = n * (2 * n + 1) * (n + 1) / 6;
    ll r2 = pow(n * (n + 1) / 2, 2);
    r2 -= s2;

    ll s3 = n * n * (n + 1) * (n + 1) / 4;
    ll r3 = pow(n * (n + 1) / 2, 3) - s3;

    ll s4 = 0;
    for (int i = 1; i  <= n; i++)
      s4 += pow(i, 4);
    ll r4 = pow(n * (n + 1) / 2, 4) - s4;
        cout << s2 << " " << r2 << " " << s3 << " " << r3 << " ";
    cout << s4 << " " << r4 << '\n';
  }
}