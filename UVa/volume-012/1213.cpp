/*
 * TheMartian0x48
 * 1213
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

// ---------------- (* Extract here *)
// ----------------
int n, k;
vi prime;

vector<vector<vi>> dp;

ll backtrack(int i, int c, int s) {
  if (i < 0) {
    return c == 0 && s == 0;
  }
  if (dp[i][c][s] == -1) {
    //skip
    dp[i][c][s] = backtrack(i - 1, c, s);
    // include
    if (c > 0 && s - prime[i] >= 0) {
      dp[i][c][s] += backtrack(i - 1, c - 1, s - prime[i]);
    }
  }
  return dp[i][c][s];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M = 1120, N;
  prime.push_back(2);
  for (int i = 3; i < M; i += 2) {
    bool flag = true;
    for (int j = 3; j * j <= i; j += 2) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      prime.push_back(i);
    }
  }
  N = prime.size();
  dp = vector<vector<vi>>(N, vector<vi>(16, vi(M + 1, -1)));

  cin >> n >> k;
  while (n || k) {
    ll res = backtrack(N - 1, k, n);
    cout << res << "\n";
    cin >> n >> k;
  }
}
