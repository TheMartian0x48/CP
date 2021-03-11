/*
 *TheMartian0x48
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

vector<int> v, u;
int r, len;

void dfs(int i) {
  
  if (r == len) {
    for (int j = 0; j < 26; j++) {
      cout << string(u[j], (char)('a' + j));
    }
    cout << "\n";
    return;
  } 
  while (i < 26 && v[i] == 0) i++;
  if (i >= 26) return;
  
  u[i] =  min(v[i], r -len);
  len += u[i];
  while(u[i] > 0) {
    dfs(i + 1);
    u[i]--;
    len--;
  }
  dfs(i + 1);  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  while (cin >> str >> r) {
    v.assign(26, 0);
    u.assign(26, 0);
    len = 0;
    for (auto a : str) v[a - 'a']++;
    dfs(0);
  }
}