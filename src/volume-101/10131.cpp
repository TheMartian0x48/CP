// @author: the__martian
// 10131
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

struct ele{
  int w, s, i;
  bool operator<(const ele& e){
    return w < e.w || (w == e.w && s > e.s);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  vector<ele> v(1005);
  int n = 0;
  while (cin >> v[n].w >> v[n].s)
    v[n].i = n, n++;


  sort(v.begin(), v.begin() + n);
  vi dp(n);
  int res = 0;
  for (int i = 0; i < n; i++) {
    int mx = 0;
    for (int j = i - 1;  j >= 0; j--) {
      if  (v[j].w != v[i].w && v[j].s > v[i].s){
        mx = max(mx, dp[j]);
      }
    }
    dp[i] = mx + 1;
    if (dp[i] > res)
      res = dp[i];
  }

  cout << res << "\n";

  stack<int> st;
  int i = n - 1;
  int w = 1e5, s = -1;
  while (res && i >= 0) {
    if (dp[i] == res && v[i].w < w && v[i].s > s) {
      st.push(v[i].i);
      res--;
      w = v[i].w; 
      s = v[i].s;
    }
    i--;
  }

  while (st.size()) {
    cout << st.top() + 1<< "\n";
    st.pop();
  }

} 
