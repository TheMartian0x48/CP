// @author: the__martian
// 574
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

vector<pii> v(20);
int n, t;
bool sol;
vi sum(50);
void solve(int s = 0, int i = 0, int idx = 0) {

  if (i == n) {
    if (s != t) return;
    sol = true;
    for (int k = 0; k < idx; k++) {
      if (k) cout << "+";
      cout << sum[k];
    }
    cout << endl;
    return;
  }

  int k = idx;
  rep(j,0,v[i].second)
    sum[k++] = v[i].first;

  per(j, v[i].second - 1, 0) {
    solve(s + v[i].first * (j + 1), i + 1, k);
    k--;
  }

  solve(s, i + 1, idx);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> t >> n, n && t) {
    int i = 0;
    rep(j,0,n) {
      int m; cin >> m;
      if (i && m == v[i].first) {
        v[i].second++;
      } else {
        ++i;
        v[i].first = m;
        v[i].second = 1;
      }
    }
    n = i + 1;
    cout << "Sums of " << t << ":\n";
    sol = false;
    solve();    
    if (!sol)
      cout << "NONE\n";
  }
}