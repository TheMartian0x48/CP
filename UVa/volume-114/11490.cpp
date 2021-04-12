/*
 * TheMartian0x48
 * UVa 11490
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

  long long s, mod = 100000007; 
  while (cin >> s, s) {
    long long x, y = 1;
    vector<long long> res;
    while (6 * y * y <= s) {
      long long t = s - 6 * y * y;
      if (t % (7 * y) == 0) {
        x = t / 7 / y;
        if (x)
          res.push_back(x);
      }
      y++;
    }
    if (sz(res) == 0) {
      cout << "No Solution Possible\n";
    } else {
      sort(rll(res));
      for (int i = 0; i < sz(res); i++) {
        // cout << res[i] << endl;
        res[i] %= mod;
        cout << "Possible Missing Soldiers = " << (2 * res[i] * res[i]) % mod << "\n";
      }
    }
    cout << "\n";
  }
}
