/*
 * TheMartian0x48 
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
vi v(1000005);
unordered_map<int, int> mp;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  if (k <= 3) {
    cout << k << "\n";
    return;
  }
  mp.clear();
  mp[1] = 1, mp[2] = 1, mp[3] = 1;
  int res = n + 1;

  for (int i = 3, j = 0; i < n; i++) {
    v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % m + 1;
    if (v[i] <= k) {
      mp[v[i]]++;
      while (mp.size() >= k) {
        res = min(res, i - j + 1);
        if (v[j] <= k) {
          mp[v[j]]--;
          if (mp[v[j]] == 0) mp.erase(v[j]);
        }
        j++;
      }
    }
  }
  if (res == n + 1) {
    cout << "sequence nai\n";
    return;
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test; cin >> test;
  
  v[0] = 1, v[1] = 2, v[2] = 3;
  for (int t = 1; t <= test; t++) {
    cout << "Case " << t << ": ";
    solve();
  }  
}