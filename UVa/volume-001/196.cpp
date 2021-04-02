/*
 * TheMartian0x48
 * UVa 196
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

vector<vi> sh(1000, vi(19000));
vector<vector<string>> v(1000, vector<string>(19000));

int cal(int r, int c) {  
  int res = 0;
  int n = v[r][c].size(), i = 0;
  while (i < n) {
    int col = 0, row = 0;
    while (v[r][c][i] >= 'A' && v[r][c][i] <= 'Z') {
      col *= 26;
      col += v[r][c][i] - 'A' + 1;
      i++;
    }
    col--;
    while (i < n && v[r][c][i] >= '0' && v[r][c][i] <= '9') {
      row *= 10;
      row += v[r][c][i] - '0';
      i++;
    }
    row--;
    i++;
    if (v[row][col].empty()) {
      res += sh[row][col];
    } else {
      res += cal(row, col);
    }
  }
  v[r][c].clear();
  sh[r][c] = res;
  return res;
}

void solve() {
  int r, c;cin >> c >> r;
  string s;
  rep(i,0,r) rep(j,0,c) {
    v[i][j] = "";
    cin >> s;
    if (s[0] == '=') {
      v[i][j] = s.substr(1, s.size() - 1);
    } else {
      sh[i][j] = stoi(s);
    }
  }
  rep(i,0,r) rep(j,0,c) {
    if (v[i][j].size()) {
      cal(i, j);
    }
  }
  rep(i,0,r) {
    rep(j,0,c) {
      if (j) cout << " ";
      cout << sh[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  int test;
  // int testcase = 1;
  cin >> test;
  while (test--) {
    // cout << "Case #" << testcase++ << ": ";
    solve();
  }
}
