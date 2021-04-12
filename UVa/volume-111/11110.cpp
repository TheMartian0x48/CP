/*
 * TheMartian0x48
 * UVa 11110
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

vector<vi> v(100, vi(100));
int n;
vi cnt;
vi dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};

void dfs(int i, int j, int c) {
 if (i <= 0 || j <= 0 || i > n || j > n || v[i][j] != c) return;
 v[i][j] = -1;
 cnt[c]++;
 for (int k = 0; k < 4; k++)
   dfs(i + dr[k], j + dc[k], c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  string s; 
  while (getline(cin, s)) {
    n = stoi(s);
    if (n == 0) break;
    cnt.assign(n, 0);
    for (int i = 1; i <= n; i++) v[i].assign(n + 1, n - 1);
    for (int i = 0; i < n - 1; i++) {
      getline(cin, s);
      stringstream ss(s);
      int c, d;
      while (ss >> c >> d) {
        v[c][d] = i;
      }
    }
    bool sol = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (v[i][j] != -1) {
          int t = v[i][j];
          dfs(i, j, t);
          if (cnt[t] != n) {
            sol = false;
            break;
          }
        }
      }
      if (!sol) break;
    }
    if (sol) cout << "good\n";
    else cout << "wrong\n";
  }
}

