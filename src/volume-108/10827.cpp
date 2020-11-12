// @author: the__martian
// 10827
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


int arr[75][75];

void solve() {
  int n; cin >> n;

  rep(i,0,n)
    rep(j,0,n) {
      cin >> arr[i][j];
      if (i - 1 >= 0)
        arr[i][j] += arr[i - 1][j];
      if (j - 1 >= 0)
        arr[i][j] += arr[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        arr[i][j] -= arr[i - 1][j - 1];
    }

  ll res = -1e15;

  rep(i,0,n) {
    rep (j,0,n) {
      rep (k,i,n) {
        ll tmp = 0;
        rep(l,j,n) {
          tmp = arr[k][l];
          if (i - 1 >= 0)
            tmp -= arr[i - 1][l];
          if (j - 1 >= 0)
            tmp -= arr[k][j - 1];
          if (i - 1 >= 0 && j - 1 >= 0)
            tmp += arr[i - 1][j - 1];
          res = max(res, tmp);
        }

        rep(l,0,j) {
          ll tmp2 = tmp + arr[k][l];
          if (i - 1 >= 0)
            tmp2 -= arr[i - 1][l];
          res = max(res, tmp2);
        }
      }

      rep(k, 0, i) {
        ll tmp = 0;
        rep(l, j, n) {
          tmp = arr[n - 1][l];
          if (i - 1 >= 0) tmp -= arr[i - 1][l];
          if (j - 1 >= 0) tmp -= arr[n - 1][j - 1];
          if (i - 1 >= 0 && j - 1 >= 0)
            tmp += arr[i - 1][j - 1];
          
          tmp += arr[k][l];
          if (j - 1 >= 0)
            tmp -= arr[k][j - 1];
          res = max(res, tmp);
        }
        rep(l, 0, j) {
          ll tmp2 = tmp;
          tmp2 += arr[k][l] + arr[n - 1][l];
          if (i - 1 >= 0)
            tmp2 -= arr[i - 1][l];
          res = max(res, tmp2);
        }
      }
    }
  }
  cout << res << endl;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) 
    solve();
}