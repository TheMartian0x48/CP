/*
 * TheMartian0x48
 * UVa 12844
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

  int test;
  int testcase = 1;
  cin >> test;
  vi v(10), u, t;
  while (test--) {
    cout << "Case " << testcase++ << ":";
    bool sol = false;
    for (int i = 0; i < 10; i++) cin >> v[i];
    sort(all(v));
    u.clear();
    for (int i1 = 50; i1 < v[0]; i1++) {
      u.push_back(i1);
      u.push_back(v[0] - i1);
      
      vector<int> p{0, 0, 0, 0, 0, 0, 1, 1, 1};
      do {
        for (int i = 0; i < 9; i++) {
          if (p[i]) u.push_back(v[i + 1] - i1);
        }
        t.clear();
        for (int i = 0; i < 5; i++) {
          for (int j = i + 1; j < 5; j++) {
            t.push_back(u[i] + u[j]);
          }
        }
        sort(all(t));
        if (t == v) {
          for (auto a : u) cout << " " << a;
          sol = true;
        }
        u.pop_back(); u.pop_back(); u.pop_back();
      } while (!sol && next_permutation(all(p)));

      u.pop_back();
      u.pop_back();
      if (sol) break;
    }
    cout << "\n";
  }
}
