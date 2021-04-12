/*
 * TheMartian0x48
 * UVa 12488
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

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  while (cin >> n) {
    vi a, b; re(a, n), re(b, n);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (b[i] != a[i]) {
        int k = i;
        while (a[k] != b[i]) k--;
        k++;
        while (k <= i) {
          swap(a[k], a[k - 1]);
          res++;
          k++;
        }
      }
    }
    cout << res << "\n";
  }
}
