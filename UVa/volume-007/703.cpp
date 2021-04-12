/*
 * TheMartian0x48
 * UVa 703
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
  vector<vi> v(101, vi(101));
  while(cin >> n) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> v[i][j];
      }
    }
    vector<pair<pii, int>> a;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k <= n; k++) {
          // draw
          if (v[i][j] == 0 && v[j][i] == 0 && v[j][k] == 0 && v[k][j] == 0 &&
            v[i][k] == 0 && v[k][i] == 0)
            a.push_back({{i, j}, k});
          else if (v[i][j] == 1 && v[j][k] == 1 && v[k][i] == 1)
            a.push_back({{i, j}, k});
          else if (v[k][j] == 1 && v[j][i] == 1 && v[i][k] == 1)
            a.push_back({{k, j}, i});
        }
      }
    }
    cout << a.size() << "\n";
    sort(all(a));
    for (int i = 0; i < sz(a); i++) 
      cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << "\n";
  }
}
