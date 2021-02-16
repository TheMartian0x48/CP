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

char ch;
int r, c;
vector<string> v(205);
string s;
int id;
void dfs(int ru, int rd, int cl, int cr) {
  if (ru > rd || cl > cr) return;
  // cout << ru << " " << rd << endl;
  // cout << cl << " " << cr << endl;
  if (id == sz(s)) return;
  if (s[id] == '0' || s[id] == '1') {
    for (int i = ru; i <= rd; i++) {
      for (int j = cl; j <= cr; j++) {
        v[i][j] = s[id];
      }
    }
    id++;
  } else {
    id++;
    int rm = ru + (rd - ru) / 2;
    int cm = cl + (cr - cl) / 2;
    dfs(ru, rm, cl, cm);
    dfs(ru, rm, cm + 1, cr);
    dfs(rm + 1, rd, cl, cm);
    dfs(rm + 1, rd, cm + 1, cr);
  }
}
string encode;

void dfs2(int ru, int rd, int cl, int cr) {
  if (ru > rd || cl > cr) return;
  bool one = true, zero = true;
  for (int i = ru; i <= rd && (one || zero); i++) {
    for (int j = cl; j <= cr && (one || zero); j++) {
      one &= v[i][j] == '1';
      zero &= v[i][j] == '0';
    }
  }
  if (one) {
    encode += '1';
  } else if (zero){
    encode += '0';
  } else {
    encode += 'D';
    int rm = ru + (rd - ru) / 2;
    int cm = cl + (cr - cl) / 2;
    dfs2(ru, rm, cl, cm);
    dfs2(ru, rm, cm + 1, cr);
    dfs2(rm + 1, rd, cl, cm);
    dfs2(rm + 1, rd, cm + 1, cr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> ch >> r >> c) {
    if (ch == 'D') {
      for (int i = 0; i < r;  i++) v[i] = string(c, '0');
      cin >> s;
      id = 0;      
      dfs(0, r - 1, 0, c - 1);
      printf("B");
      printf("%4d%4d\n", r, c);
      int k = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (k && (k % 50 == 0)) printf("\n");
          printf("%c", v[i][j]);
          k++;
        }
      }
    } else {
      char ch;
      int count = 0, i = 0;
      v[0].clear();
      while(count < r * c) {
        cin >> ch;
        if (ch == '0' || ch == '1') {
          v[i] += ch;
          if (sz(v[i]) == c) {
            i++;
            v[i].clear();
          }
          count++;
        }
      }

      encode.clear();
      id = 0;
      dfs2(0, r - 1, 0, c - 1);
      printf("D");
      printf("%4d%4d\n", r, c);
      for (int i = 0; i < encode.size(); i++) {
        if (i && (i % 50 == 0)) printf("\n");
        printf("%c", encode[i]);
      }
    } 
    printf("\n");
    fflush(stdout);
  }
}

