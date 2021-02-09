// author : the__martian
// 10940 
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

  int N = 500005;
  vector<int> v(N);
  v[1] = 1;
  v[2] = 2;
  v[3] = 2;
  for (int i = 4; i < N; i++) {
    if (i % 2) {
      int m = i / 2 + 1;
      v[i] = 2 * (v[m] - 1);
    } else {
      int m = i / 2;
      v[i] = 2 * v[m];
    }
  }
  int n;
  while (cin >> n, n) {
    cout << v[n] << "\n";
  }
}
