// author : the__martian
// 10600 
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

struct DSU{
  int n;
  vector<int> par, s;
  DSU(int m) {
    n = m;
    par.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++)
      par[i] = i, s[i] = 1;
  }
  int find(int x){
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);
  }

  void merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return;
    if (s[a] > s[b]) swap(a, b);
    s[b] += s[a];
    par[a] = b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test; cin >> test;
  while (test--) {
    int n, m, a, b, c; cin >> n >> m;
    vector<pair<int, pii>> v;
    vector<bool> tag;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      v.push_back({c, {a, b}});
      tag.push_back(false);
    }
    sort(all(v));
    int best = 0, second_best = INT_MAX, i = 0;
    DSU dsu(n + 1);
    for (auto p : v) {
      c = p.first;
      a = p.second.first;
      b = p.second.second;
      if (dsu.find(a) != dsu.find(b)) {
        best += c;
        dsu.merge(a, b);
        tag[i] = true;
        DSU mst(n + 1);
        int tmp = 0, j = -1;
        for (auto e : v) {
          j++;
          if (tag[j]) {
            continue;
          }
          a = e.second.first;
          b = e.second.second;
          c = e.first;
          if (mst.find(a) != mst.find(b)) {
            tmp += c;
            mst.merge(a, b);
          }
        }
        int f = mst.find(1);
        for (int i = 1; i <= n; i++) {
          if (f != mst.find(i)) {
            tmp = INT_MAX;
            break;
          }
        }
        second_best = min(second_best, tmp);
        tag[i] = false;
      }
      i++;
    }
    cout << best << " " << second_best << "\n";
  }
}
