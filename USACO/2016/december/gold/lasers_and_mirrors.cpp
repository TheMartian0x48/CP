
/*
 * TheMartian0x48
 * USACO 2016 December Contest, Gold
 * Problem 3. Lasers and Mirrors
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
int n, xl, yl, xb, yb;
unordered_map<int, vector<int>> x, y;
unordered_set<int> visx, visy;

int bfs() {
  queue<pii> q;
  int layer = 0;
  q.push({xl, yl});
  while (q.size()) {
    int len = q.size();
    while (len--) {
      int px = q.front().first;
      int py = q.front().second;
      q.pop();
      if (px == xb || py == yb) return layer;
      if (visx.count(px) == 0) {
        for (auto e : x[px]) {
          if (e != py)
            q.push({px, e});
        }
        visx.insert(px);
      }
      if (visy.count(py) == 0) {
        for (auto e : y[py]) {
          if (e != px)
            q.push({e, py});
        }
        visy.insert(py);
      }
    }
    layer++;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  usaco("lasers");

  cin >> n >> xl >> yl >> xb >> yb;
  int a, b;
  while (n--) {
    cin >> a >> b;
    x[a].push_back(b);
    y[b].push_back(a);
  }
  cout <<  bfs();
}
