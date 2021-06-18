
/*
 * TheMartian0x48
 * USACO 2014 December Contest, Gold
 * Problem 3. Cow Jog
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
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  usaco("cowjog");
  
  int n; cin >> n; 
  ll T; cin >> T;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v));
  multiset<ll> st;
  for (int i = 0; i < n; i++) {
    ll d = v[i].first + v[i].second * T;
    auto it = st.lower_bound(d);
    if (it == st.begin()) {
      st.insert(d);
    } else {
      st.erase(--it);
      st.insert(d);
    }
  }
  cout << st.size();
}
