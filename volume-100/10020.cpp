// author : the__martian
// 10020
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

bool cst(const pii &a, const pii &b) {
  return a.second < b.second || (a.second == b.second && a.first < b.first);
}

bool cust(const pii& a, const pii& b) {
  return a.first < b.first
    || (a.first == b.first && a.second < b.second);
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  int m;
  vector<pii> v(100005);
  while (t--) {
    cin >> m;
    int a, b, n = 0;
    while (cin >> a >> b, a || b) {
      if (a > m || b < 0 || a == b)
        continue;
      
      v[n++] = {a, b};
    }

    sort(v.begin(), v.begin() + n);
    vector<pii> res;
    int tar = 0, start = 0;
    while (tar < m) {
      pii p;
      for (int i = start; i < n; i++) {
        if (tar < v[i].first) {
          start  = i;
          break;
        }
        if (tar >= v[i].first && tar <= v[i].second && p.second < v[i].second) {
          p = v[i];
        }
        start = i;
      }
      if (p.first == p.second || p.second == tar)
        break;
      else  {
        res.push_back(p);
        tar = p.second;
      }
    }
    if (res.size() == 0 
      || (res[sz(res) - 1].second < m)) {
        cout << 0 << "\n";
      } else {
        cout << res.size() << "\n";
        for (auto p : res) {
          cout << p.first << " " << p.second << '\n';
        }
      }
    if (t)
      cout << "\n";
  }
}

