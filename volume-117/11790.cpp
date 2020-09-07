// @author: the__martian
// UVa 11790

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 2000;
vi h(N), w(N);
vi dp1(N), dp2(N);
void solve() {
int n; scanf("%d", &n);
  
  rep(i,0,n) scanf("%d", &h[i]);
  rep(i,0,n) scanf("%d", &w[i]);
  
  int mx1 = 0, mx2 = 0;
  rep(i,0,n) {
    int tmp = 0, tmp2 = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (h[j] < h[i]) {
        tmp = max(tmp, dp1[j]);
      }
      if (h[j] > h[i]) {
        tmp2 = max(tmp2, dp2[j]);
      }
    }
    dp1[i] = tmp + w[i];
    mx1 = max(mx1, dp1[i]);
    dp2[i] = tmp2 + w[i];
    mx2 = max(mx2, dp2[i]);
  }

  if (mx1 >= mx2) {
    printf("Increasing (%d). Decreasing (%d).\n", mx1, mx2);
  } else {
    printf("Decreasing (%d). Increasing (%d).\n", mx2, mx1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; scanf("%d", &t);
  rep(i,0,t) {
    printf("Case %d. ", i + 1);
    solve();
  }
}