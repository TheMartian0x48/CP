/*
 * TheMartian0x48
 * Uva 10616
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
using ll = unsigned long long;
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
int n, sum;
vi v(25);
vector<vector<bool>> dp(25, vector<bool>(205));
bool solve(int i, int s = 0) {
  if (i < 0) {
    return 2 * s == sum;
  }
  if (dp[i][s]) return true;
  //skip
  dp[i][s] = solve(i - 1, s);
  //include
  if (!dp[i][s] && 2 * (s + v[i]) <= sum) {
    dp[i][s] = solve(i - 1, s + v[i]);
  }
  return dp[i][s];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  string s; getline(cin, s);
  int test = stoi(s);
  while (test--) {
    getline(cin, s);
    stringstream ss(s);
    n = 0;
    sum = 0;
    while(ss >> v[n]){
      sum += v[n++];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j * 2 <= sum; j++)
        dp[i][j] = false;
    }
    if (solve(n - 1)) cout << "YES\n";
    else cout << "NO\n";
  }
}
