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

struct dsu{
  vector<int> arr, size, money;
  
  void init(int n) {
    arr.resize(n);
    money.resize(n);
    size.resize(n, 1);
    rep(i,0,n) arr[i] = i;
  }

  int find(int x) {
    return x == arr[x] ? x : arr[x] = find(arr[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    else if (size[x] < size[y]) swap(x, y);
    arr[y] = x;
    size[x] += size[y];
    money[x] += money[y];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  dsu st;
  while (t--) {
    int n, m; cin >> n >> m;
    st.init(n);
    rep(i,0,n) {
      cin >> st.money[i];
    }
    while (m--) {
      int a, b;
      cin >> a >> b;
      st.merge(a, b);
    }
    bool sol = true;
    for (int i = 0; i < n; i++) {
      if (i == st.arr[i] && st.money[i] != 0) {
        sol = false;
        break;
      }
    }
    cout << (sol ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }
}

