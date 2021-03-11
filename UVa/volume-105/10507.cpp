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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  while (cin >> n) {
    unordered_map<char, int> mp;
    int m; cin >> m;
    string s; cin >> s;
    vi wake(n, 0);
    for (int i = 0; i < 3; i++) { 
      mp[s[i]] = mp.size();
      wake[mp[s[i]]] = 1;
    }

    vector<vi> g(n);
    while (m--) {
      cin >> s;
      for (int i = 0; i < 2; i++) {
        if (mp.count(s[i]) == 0)
          mp[s[i]] = mp.size();
      }
      g[mp[s[0]]].push_back(mp[s[1]]);
      g[mp[s[1]]].push_back(mp[s[0]]);
    }
    int res = 0;
    stack<int> st;
    while (true) {
      bool waked = false;
      for (int i = 0; i < n; i++) {
        if (wake[i]) continue;
        int c = 0;
        for (auto a : g[i])
          c += wake[a];
        if (c >= 3) waked = true, st.push(i);
      }
      if (waked) res++;
      else break;
      while(st.size())
        wake[st.top()] = 1, st.pop();
    }
    bool sol = true;
    for (int i = 0; i < n; i++)
      sol = sol && wake[i];
    if (!sol)
      cout << "THIS BRAIN NEVER WAKES UP\n";
    else 
      cout << "WAKE UP IN, " << res << ", YEARS\n";
  }
}

