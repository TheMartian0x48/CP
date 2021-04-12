/*
 * TheMartian0x48
 * UVa 10662
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t, r, h;
  vector<vi> T(21, vi(21)), R(21, vi(21)), H(21, vi(21));
  while (cin >> t >> r >> h) {
    rep(i,1,t + 1){
      rep(j,0,r + 1) cin >> T[i][j];
    }
    rep(i,1,r + 1){
      rep(j,0,h + 1) cin >> R[i][j];
    }
    rep(i,1,h + 1){
      rep(j,0,t + 1) cin >> H[i][j];
    }
    int cost = INT_MAX, tt, rr, hh;
    rep(i,1,t + 1){
      rep(j,1,r + 1) {
        rep(k,1,h + 1) {
          if (T[i][j]|| R[j][k] || H[k][i]) continue;
          int tmp = T[i][0] + R[j][0] + H[k][0];
          if (tmp < cost) cost = tmp, tt = i,  rr = j, hh = k;
        }
      }
    }
    if (cost == INT_MAX)
      cout << "Don't get married!\n";
    else 
      cout << tt - 1<< " " << rr - 1<< " " << hh - 1<< ":" << cost << "\n";
  }
}
