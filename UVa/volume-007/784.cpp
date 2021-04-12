/*
 * TheMartian0x48
 * UVa 784
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

vector<string> v;

vi dr{-1, 0, 0, 1}, dc{0, -1, 1, 0};

void dfs(int r, int c) {
  if (r < 0 || c < 0 || r >= sz(v) || c >= sz(v[r])) return;
  if (!(v[r][c] == ' '|| v[r][c] == '*') || v[r][c] == '#') return;
  v[r][c] = '#';
  for (int i = 0; i < 4; i++) {
    dfs(r + dr[i], c + dc[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s; getline(cin, s);
  int n; n = stoi(s);
  while (n--) {
    v.clear();
    while(getline(cin, s), s[0] != '_') 
      v.push_back(s);
    bool f = false;
    for (int i = 0; i < sz(v); i++) {
      for (int j = 0; j < sz(v[i]); j++) {
        if (v[i][j] == '*') {
          dfs(i, j);
          f = true;
          break;
        }
      }
      if (f) break;
    }
    for (auto &a : v) cout << a << "\n";
    cout << s << "\n";
  }
}
