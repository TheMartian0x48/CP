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

struct dsu{
  int size;
  vi v, p;
  void clear(int n) {
    size = n + 1;
    v.assign(size, 1);
    p.resize(size);
    for (int i = 0; i < size; i++) p[i] = i;
  }
  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }
  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a == b) return;
    if (v[a] <= v[b]) swap(a, b);
    v[a] += v[b];
    p[b] = a;
  }
};
dsu st;

void solve() {
  string s, t;
  int a, b, n;
  getline(cin, s);
  n = stoi(s);
  st.clear(n);
  int yes = 0, no = 0;
  while (true) {
    getline(cin, s);
    if (s == "") break;
    stringstream ss(s);
    ss >> t >> a >> b;
    if (t[0] == 'q') {
      st.find(a) == st.find(b) ? yes++ : no++;
    } else {
      st.merge(a, b);
    }
  }
  cout << yes <<","  << no << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // clang-format off
  string s; getline(cin , s);
  int test;
  test = stoi(s);
  getline(cin, s);
  while (test--) {
    solve();
    if (test) cout << "\n";
  }
  // clang-format on
}
