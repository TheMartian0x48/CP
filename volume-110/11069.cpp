// @author: the__martian
// 11069
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

vector<ll> v(80, 0);

void Cal() {
  int n = 76;
  v[1] = v[2] = v[3] = 1; v[4] = 2;
  for (int i = 5; i <= n; i++) {
    v[i] = v[i - 2] + v[i - 3];
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Cal();

  int n;
  while (cin >> n) {
    ll res = v[n] + v[n - 1];
    cout << res << "\n";
  }
}