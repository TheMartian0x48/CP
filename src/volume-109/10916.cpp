// @author: the__martian
// 10916
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
  
  int n;
  while (cin >> n, n) {
    n = n / 10 * 10;
    double y = (n - 1960) / 10 + 2;
    double res = 1;
    double d = 0, dd = 0;
    while (dd < y) {
      d += log2(res++);
      dd = log2(d);
    }
    cout << res - 2 << "\n";
  }
}