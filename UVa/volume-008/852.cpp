/*
 * TheMartian0x48
 * UVa 852
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
int n;
vector<string> v;
bool black, white;
vi dr{-1, 0, 0, 1}, dc{0, -1, 1, 0};

int dfs(int r, int c) {
  if (r < 0 || c < 0 || r >= 9 || c >= 9) {
    return 0;
  } else if (v[r][c] == 'X') {
    black = true;
    return 0;
  } else if (v[r][c] == 'O') {
    white = true;
    return 0;
  } else if (v[r][c] == 'V') return 0;
  v[r][c] = 'V';
  int res = 1;
  for (int i = 0; i < 4; i++) 
     res += dfs(r + dr[i] , c + dc[i]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;
  v.resize(9);
  for (int t = 0; t < n; t++) {
    rep(i,0,9) cin >> v[i];
    int b = 0, w = 0;
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (v[r][c] == '.') {
          black = false, white = false;
          int cnt = dfs(r, c);
          if (black && white) continue;
          if (black) b += cnt;
          else if(white) w += cnt;
        } else if (v[r][c] == 'X') b++;
        else if (v[r][c] == 'O') w++;
      }
    }
    cout << "Black " << b << " White " << w << "\n";
  }
}
