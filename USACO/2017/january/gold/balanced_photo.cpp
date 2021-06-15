
/*
 * TheMartian0x48 
 * USACO 2017 January Contest, Gold
 * Problem 1. Balanced Photo
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
  void set(int i) {
    for (; i < size; i |= (i + 1)) {
      tree[i] += 1;
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
  usaco("bphoto");
  int n; cin >> n;
  vector<int> v; re(v, n);
  auto u = v;
  sort(all(u));
  unordered_map<int, int> index;
  for (int i = 0; i < n; i++) {
    if (index.count(u[i]) == 0)
      index[u[i]] = index.size();
  }
  vector<int> left(n);
  ft tree(n);
  for (int i = 0; i < n; i++) {
    int id = index[v[i]];
    left[i] = i - tree.get(id);
    tree.set(id);
  }
  int res = 0;
  tree.tree.assign(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    int id = index[v[i]];
    int r = (n - i - 1) - tree.get(id);
    res += (r > 2 * left[i]) || (left[i] > 2 * r);
    tree.set(id);
  }
  cout << res;
}
