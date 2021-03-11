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
  vi par, size, sum;
  void init(int n) {
    par.resize(2*n+2);
    size.resize(2*n+2);
    sum.resize(2*n+2,0);
    for (int i = 1; i <= n; i++) {
      par[i] = i + n, par[i + n] = i + n;
      sum[i] = 0, sum[i + n] = i;
      size[i + n] = 1;
    }
  }

  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (size[a] < size[b])
      swap(x, y), swap(a, b);
    par[b] = a;
    size[a] += size[b];
    sum[a] += sum[b];
  }

  void remove(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    size[a]--;
    sum[a] -= x;
    par[x] = b;
    sum[b] += x;
    size[b]++; 
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dsu st;
  int n;
  while (cin >> n) {
    int m; cin >> m;
    int t, p, q;
    st.init(n);
    while (m--) {
      cin >> t >> p;
      if (t == 1) cin >> q, st.merge(p, q);
      else if (t == 2) cin >> q, st.remove(p, q);
      else {
        q = st.find(p);
        cout << st.size[q] << " " << st.sum[q] << "\n";
      }
    }
  }
}

