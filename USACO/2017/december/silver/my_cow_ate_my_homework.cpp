/*
 * TheMartian0x48 
 * USACO 2017 December Contest, Silver
 * Problem 1. My Cow Ate My Homework
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

  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);

  int n; cin >> n;
  vi v(n);
  ll sum = 0;
  re(v, n);
  multiset<int> st;
  rep(i,0,n) {
    sum += v[i];
    st.insert(v[i]);
  }
  double avg = 0;
  vector<double> mx(n);
  rep(i,0,n - 2) {
    st.erase(st.find(v[i]));
    sum -= v[i];
    ll marks = sum - *st.begin();
    mx[i] = (double)marks / (n - i - 2);
    avg = max(mx[i], avg);
  }
  rep(i,0,n-2) {
    if (abs(mx[i] - avg) < 1e-6) {
      cout << i + 1 << "\n";
    }
  } 
}