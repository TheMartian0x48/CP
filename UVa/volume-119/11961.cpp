/*
 * TheMartian0x48
 * UVa 11961
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
// clang-format on
int n, k;
string s, dns="ACGT";
vector<string> v;

void cs(int i = 0, int c = 0) {
  if (c > k) return;
  if (i == n) {
      v.push_back(s);
    return;
  }

  for (auto a : dns) {
    if (a == s[i]) cs(i + 1, c);
    else {
      char ch = s[i];
      s[i] = a;
      cs(i + 1, c + 1);
      s[i] = ch;
    }
  }
}

void solve() {
  cin >> n >> k >> s;
  v.clear();
  cs();
  cout << sz(v)<< "\n";
  for (auto a : v) cout << a << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  // int testcase = 1;
  cin >> test;
  while (test--) {
    // cout << "Case #" << testcase++ << ": ";
    solve();
  }
}
