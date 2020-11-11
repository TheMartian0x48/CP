// author : the__martian
// 497
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  getline(cin, s);
  int test = stoi(s);
  vector<int> v(10000), par(10000), inc(10000);
  getline(cin, s);
  while (test--) {
    int n = 0;
    while (getline(cin, s)) {
      if (s == "")
        break;
      v[n++] = stoi(s);
    }
    inc.assign(n, 0);
    int res = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int p = -1;
      int mx = 0;
      for (int j = 0; j < i; j++) {
        if (v[j] < v[i] && inc[j] > mx) {
          p = j;
          mx = inc[j];
        }
      }
      par[i] = p;
      inc[i] = 1 + mx;
      if (inc[i] > res) {
        res = inc[i];
        last = i;
      }
    }
    res = 0;
    stack<int> st;
    while (last != -1) {
      st.push(v[last]);
      last = par[last];
      res++;
    }
    cout << "Max hits: " << res << "\n";
    while (st.size()) {
      cout << st.top() << "\n";
      st.pop();
    }
    if (test)
      cout << "\n";
  }
}
