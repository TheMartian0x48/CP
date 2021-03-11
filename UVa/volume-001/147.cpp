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
const int N = 30005, M = 11;
vi coin{5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<vii>  dp(N, vii(15, -1));
int tar;
ll backtrack(int s, int i) {
  if (i < 0) {
    return s == 0;
  }
  if (dp[s][i] == -1) {
    dp[s][i] = 0;
    int tmp = s;
    while (tmp >= 0) {
      dp[s][i] += backtrack(tmp, i - 1);
      tmp -= coin[i];
    }
  }
  return dp[s][i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  double n;
  while(true) {
    scanf("%lf", &n);
    if (n == 0.0) break;
    tar = (int)(n * 10000) / 100;
    ll res = backtrack(tar, 10);
    printf("%6.2lf%17lld\n", n, res);
  }
}
