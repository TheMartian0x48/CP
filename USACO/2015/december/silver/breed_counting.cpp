/*
 * TheMartian0x48 
 * USACO 2015 December Contest, Silver
 * Problem 3. Breed Counting
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

// ---------------- (* Extract here *)
// ----------------



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<vi> v(n, vi(3, 0));
  rep(i,0,n) {
    int a; cin >> a;
    v[i][a - 1]++;
    if (i) {
      v[i][0] += v[i - 1][0];
      v[i][1] += v[i - 1][1];
      v[i][2] += v[i - 1][2];
    }
  }
  while(q--) {
    int a, b;
    cin >> a >> b;
    a-=2, b--;
    int r1 = v[b][0];
    int r2 = v[b][1];
    int r3 = v[b][2];
    if(a >= 0) r1 -= v[a][0], r2 -= v[a][1], r3 -= v[a][2];
    cout << r1 << " " << r2 << " " << r3 << "\n";
  }
}