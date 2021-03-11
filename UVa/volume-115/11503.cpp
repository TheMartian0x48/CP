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
  vector<int> arr, size;
  
  void init(int n) {
    arr.resize(n);
    size.resize(n, 1);
    rep(i,0,n) arr[i] = i;
  }

  int find(int x) {
    return x == arr[x] ? x : arr[x] = find(arr[x]);
  }

  int merge(int x, int y) {
    if (x == (int)arr.size()) {
      arr.push_back(x);
      size.push_back(1);
    }
    if (y == (int)arr.size()) {
      arr.push_back(y);
      size.push_back(1);
    }
    x = find(x);
    y = find(y);
    if (x == y) return size[x];
    else if (size[x] < size[y]) swap(x, y);
    arr[y] = x;
    size[x] += size[y];
    return size[x];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  dsu st;
  string a, b;
  while (t--) {
    st.init(0);
    int f; cin >> f;
    unordered_map<string, int> mp;
    while(f--) {
      cin >> a >> b;
      if (mp.count(a) == 0) {
        mp[a] = mp.size();
      }
      if (mp.count(b) == 0) {
        mp[b] = mp.size();
      }
      cout << st.merge(mp[a], mp[b]) << "\n";
    }
  }
}

