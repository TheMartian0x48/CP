/*
 * TheMartian0x48
 * Uva 11407
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
int N = 10005;
vector<int> dp(N, -1);

int cs(int j) {
  if (j <= 3) return dp[j];
  if (dp[j] == j) {
    int r = INT_MAX;
    rep(i,2, (int)sqrt(j) + 1) {
      int s = i * i, k = 1;
      while (s <= j) {
        r = min(r, k + cs(j - s));
        k++;
        s += i * i;
      }
    }
    dp[j] = r;
  }
  return dp[j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  rep(i,0,N) dp[i] = i;
  int test;
  cin >> test;
  while (test--) {
    int t; cin >> t;
    cout << cs(t) << "\n";
  }
}
