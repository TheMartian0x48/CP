// author : the__martian
// 10751 
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

  int test; cin >> test;
  while (test--) {
    int n; cin >> n;
    int total = n * n;
    int dash, diag;
    if (n % 2) {
      dash = (n - 1) / 2 * 8;
      diag = total - dash;
      if (n == 1)
        dash = diag = 0;
    } else {
      dash = 4 + (n - 2) / 2 * 8;
      diag = total - dash;
    }
    double res = dash + diag * sqrt(2);
    printf("%.3lf\n", res);
    if (test)
      printf("\n");
  }
}
