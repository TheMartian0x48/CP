
/*
 * TheMartian0x48 
 * USACO 2017 February Contest, Gold
 * Problem 3. Why Did the Cow Cross the Road III
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

struct ft {
  vector<int> tree;
  int size;
  ft(int n) {
    size = n;
    tree.assign(n, 0);
  }
  void set(int i, int v) {
    for (; i < size; i |= (i + 1)) {
      tree[i] += v;
    }
  }
  int get(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      res += tree[i];
    }
    return res;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  usaco("circlecross");
  int n; cin >> n;
  vi v; re(v, 2 * n);
  vi seen(n + 1, -1);
  ft tree(2 * n);
  int res = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (seen[v[i]] != -1) {
      tree.set(seen[v[i]], -1);
      int t = tree.get(i) - tree.get(seen[v[i]]);
      res += t;
    } else {
      seen[v[i]] = i;
      tree.set(i, 1);
    }
  }
  cout << res;
}
