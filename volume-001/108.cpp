// @author: the__martian
// 108
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
  int arr[105][105];
  while (cin >> n) {
    rep(i,0,n) 
      rep(j,0,n) {
        cin >> arr[i][j];
        if (i) arr[i][j] += arr[i-1][j];
        if (j) arr[i][j] += arr[i][j-1];
        if (i && j) arr[i][j] -= arr[i-1][j-1];
      }

    ll res = -1e15;
    rep(i,0,n) {
      rep(j,0,n) {
        rep(k,i,n) {
          rep(l,j,n){
            ll s = arr[k][l];
            if (i - 1 >= 0) s -= arr[i - 1][l];
            if (j - 1 >= 0) s -= arr[k][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
              s += arr[i - 1][j - 1];
            res = max(res, s);
          }
        }
      }
    }
    cout << res << "\n";
  }
}