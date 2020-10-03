// author: the__martian
// 11401
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  using ll = long long;
  int N = 1e6+5;
  vector<ll> v(N,0);
  ll triangle = 0;
  
  for (int i = 4; i < N; i++) {
    if (i % 2) {
      v[i] = triangle * 2;
    } else {
      v[i] = triangle * 2 + (i / 2 - 1);
      triangle += i / 2 - 1;
    }
    v[i] += v[i - 1];
  }

  ll n;
  while (cin >> n, n >= 3) {
    cout << v[n] << "\n";
  }
}
