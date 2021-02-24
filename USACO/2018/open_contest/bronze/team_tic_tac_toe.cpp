/*
 *TheMartian0x48
 *USACO 2018 US Open Contest, Bronze
 *Problem 1. Team Tic Tac Toe
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

vector<string> v(3);
unordered_multiset<char> st;

bool win(char A, char B, int t = 0) {
    // row
    for (int j = 0; j < 3; j++) {
      st.clear();
      bool f = false, s = false;
      for (int k = 0; k < 3; k++) {
        if (A == v[j][k]) {
          st.insert(v[j][k]);
          f = true;
        }
        if (B == v[j][k]) {
          st.insert(v[j][k]);
          s = true;
        }
      }
      if (!t && st.size() == 3)
        return true;
      if (t && f && s && st.size() == 3) return true;
    }
    // col
    for (int k = 0; k < 3; k++) {
      st.clear();
      bool f = false, s = false;
      for (int j = 0; j < 3; j++) {
        if (A == v[j][k]) {
          st.insert(v[j][k]);
          f = true;
        }
        if (B == v[j][k]) {
          st.insert(v[j][k]);
          s = true;
        }
      }
      if (!t && st.size() == 3)
        return true;
      if (t && f && s && st.size() == 3) return true;
    }
    st.clear();
    bool f = false, s = false;
    for (int i = 0; i < 3; i++) {
      if (A == v[i][i]) {
        st.insert(v[i][i]);
        f = true;
      }
      if (B == v[i][i]) {
        st.insert(v[i][i]);
        s = true;
      }
    }
    if (!t && st.size() == 3)
      return true;
    if (t && f && s && st.size() == 3) return true;
    st.clear();
    f = false, s = false;
    for (int i = 0; i < 3; i++) {
      if (A == v[i][2 - i]) {
        st.insert(v[i][2 - i]);
        f = true;
      }
      if (B == v[i][2 - i]) {
        st.insert(v[i][2 - i]);
        s = true;
      }
    }
    if (!t && st.size() == 3)
      return true;
    if (t && f && s && st.size() == 3) return true;
    return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  rep(i,0,3) cin >> v[i];
  int res = 0;

  for (int i = 0; i < 26; i++) {
    res += win('A' + i, '.');
  }
  cout << res << "\n";
  res = 0;
  for (char A = 'A'; A <= 'Z'; A++) {
    for (char B = A + 1; B <= 'Z'; B++) {
      res += win(A, B, 1);
    }
  }
  cout << res << "\n";
}
