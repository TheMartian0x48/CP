/*
 *TheMartian0x48
 */
/*
Problem: https://www.codechef.com/FEB21C/problems/TEAMNAME
Solution: https://www.codechef.com/viewsolution/42313218
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

void solve()
{
  int n;
  cin >> n;
  unordered_map<char, unordered_set<string>> mp;
  string s;
  rep(i,0,n) {
    cin >> s;
    mp[s[0]].insert(s.substr(1, s.size()));
  }
  int res = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (mp.count(ch) == 0) continue;
    for (char dh = ch + 1; dh <= 'z'; dh++) {
      if (mp.count(dh) == 0) continue;
      int c1 = 0, c2 = 0;
      for (auto &str : mp[ch]) {
        c1 += !mp[dh].count(str);
      }
      for (auto &str : mp[dh]) {
        c2 += !mp[ch].count(str);
      }
      res += 2 * c1 * c2;
    }
  }
  cout << res << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;
  while (test--)
    solve();
}
