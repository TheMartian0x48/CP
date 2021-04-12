/*
 * TheMartian0x48
 * UVa 12527
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
// clang-format on

bool valid(int n) {
  vi v(10, 0);
  while (n) {
    int d = n % 10; n /= 10;
    v[d]++;
    if (v[d] > 1) return false;
  }
  return true; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vi v;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l  = 0; l < 10; l++) {
          int d = i * 1000 + j * 100 + k * 10 + l;
          if (valid(d)) v.push_back(d);
        }
      }
    }
  }
  sort(all(v));
  int n, m;
  while (cin >> n >> m) {
    int r = lower_bound(all(v), m) - v.begin();
    int l = lower_bound(all(v), n) - v.begin();
    int res = 0;
    if (v[l] > m) res = 0;
    else {
      if (v[r] > m) r--;
      res = r - l + 1;
    }
    cout << res << "\n";
  }
}
