/*
UVa 12801
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

  int c, n;
  while(cin >> c >>n) {
    vi v; re(v, n);
    if (n == 1) {
      cout << "S\n";
      continue;
    }
    bool fine, fine2;
    for (int i = 0; i < c / n; i++) {
      fine = true, fine2 = true;
      int last = i;
      int j = 0;
      while (v[j] < i) j++;
      for (int k = 0; k < n; k++, j = (j + 1) % n) {
        if ((v[j] >= last && v[j] - last >= c / n) || (v[j] < last  && v[j] - last + c >= c / n)){
          fine = false;
          break;
        }
        last += c / n;
      }
      if (fine) break;
      j = 0;
      while (v[j] < i) j++;
      double l = i + 0.5;
      
      for (int k = 0; k < n; k++, j = (j + 1) % n) {
        if ((v[j] >= l && v[j] - l >= c / n) || (v[j] < l  && v[j] - l + c >= c / n)){
          fine2 = false;
          break;
        }
        l += c / n;
      }
      if (fine2) break;
    }
    if (fine || fine2) cout << "S\n";
    else cout << "N\n";
  }
}
