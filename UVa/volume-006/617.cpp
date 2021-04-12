/*
 * TheMartian0x48
 * UVa 617
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

  int n, test = 1; 
  while (cin >> n, n != -1) {
    cout << "Case " << test++ << ": ";
    vector<double> dis(n);
    vector<int> red(n), green(n), yellow(n);
    for (int i = 0;i < n; i++) {
      cin >> dis[i] >> green[i] >> yellow[i] >> red[i];
    }
    vector<int> res;
    for (int i = 30; i <= 60; i++) {
      bool valid = true;
      for (int j = 0; j < n; j++) {
        double sec = dis[j] * 3600 / i;
        double r = green[j] + yellow[j] + red[j];
        while (r < sec) {
          r += green[j] + yellow[j] + red[j];
        }
        if (sec > r - red[j] && sec < r) {
          valid = false;
          break;
        }
      }
      if (valid) res.push_back(i);
    }
    if (res.size() == 0) {
      cout << "No acceptable speeds.\n";
      continue;
    }
    n = res.size();
    bool first = true;
    int s = res[0], f = res[0] - 1;
    for (int i = 0; i < n; i++) {
      if (res[i] == 1 + f) {
        f = res[i];
        continue;
      }
      if (!first) cout << ", ";
      first = false;
      if (s == f) {
        cout << s;
      } else {
        cout << s << "-" << f;
      }
      s = res[i];
      f = res[i];
    }
    if (!first) cout << ", ";
    if (n > 1 && s != f) {
      cout << s << "-" << f;
    } else if (n > 1) {
      cout << s;
    }
    cout << "\n";
    // for (auto a : res) cout << a << " ";
    // cout << "\n";
  }
}
