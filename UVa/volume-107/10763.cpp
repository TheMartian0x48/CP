// @author: the__martian
// 10763
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

  vector<pii> v(500005);
  int n; 
  while (cin >> n, n) {
    rep(i,0,n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.begin() + n);

    bool flag = true;
    int i = 0;
    while (i < n && flag) {
      int j = upper_bound(v.begin() + i, v.begin() + n, v[i]) - v.begin();
      pii p = make_pair(v[i].second, v[i].first);
      int k = upper_bound(v.begin(), v.begin() + n, p) - lower_bound(v.begin(), v.begin() + n, p);

      if (k != j - i)   {
        flag = false;
        break;
      }
      i = j;
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
}