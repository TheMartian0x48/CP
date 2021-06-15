
/*
 * TheMartian0x48 
 * USACO 2017 US Open Contest, Gold
 * Problem 3. Modern Art 2
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
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on
int n, res = 0;
vector<int> v, r_end;
vector<bool> seen;

bool cs(int i, int j, int d = 1) {
  res = max(d, res);
  seen[v[i]] = true;
  for (++i; i < j;) {
    int k = r_end[v[i]];
    if (k > j) return true;
    else if (v[i] == v[j]) {
      i++;
      continue;
    }
    if (seen[v[i]] || cs(i, r_end[v[i]], d + 1)) return true;
    i = r_end[v[i]] + 1;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("art2");
  cin >> n;
  re(v, n);
  r_end.resize(n + 1);
  rep(i,0,n) {
    r_end[v[i]] = i;
  }
  seen.assign(n + 1, false);
  seen[0] = true;
  bool wrong = false;
  for (int i = 0; i < n;) {
    while (i < n && v[i] == 0) i++;
    wrong = cs(i, r_end[v[i]]);
    if (wrong) {
      res = -1;
      break;
    }
    i = r_end[v[i]] + 1;
  }
  cout << res;
}
