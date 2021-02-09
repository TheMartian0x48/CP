// @author: the__martian
// 301

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

struct order{
  int start, dest, no;
  friend bool operator<(const order& a, const order& b) {
    return a.start < b.start || (a.start == b.start && a.dest < b.dest);
  }
};

int c, s, n;
vector<order> v(30);
vi stop(30, 0);
ll res;

void solve(int idx = 0, int p = 0, ll s = 0, int l = 0)  {

  if (idx == n) {
    res = max(res, s);
    return;
  }

  for (int i = l + 1; i <= v[idx].start; i++) {
    p -= stop[i];
  }

  if (p + v[idx].no <= c) {
    stop[v[idx].dest] += v[idx].no;
    solve(idx + 1, p + v[idx].no, s + v[idx].no * (v[idx].dest - v[idx].start), v[idx].start);
    stop[v[idx].dest] -= v[idx].no;
  }
  solve(idx + 1, p, s, v[idx].start);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  while (cin >> c >> s >> n, c || s || n) {
    
    rep(i,0,n)
      cin >> v[i].start >> v[i].dest >> v[i].no;

    sort(v.begin(), v.begin() + n);

    rep(i,0,30) stop[i] = 0;
    res = 0;
    solve();
    cout << res << "\n";
  }
}