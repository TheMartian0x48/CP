/*
 * TheMartian0x48
 * UVA 10624
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

int x, y;
string s(35, '.');


int mod(int n) {
  int r = 0, t = 1;
  for (int i = n - 1; i >= 0; i--) {
    r += ((s[i] - '0') * t) % n;
    r %= n;
    t = (t * 10) % n;
  }
  return r;
}

bool cs(int i = 0) {
  if (i == y) {
    for (int j = 0; j < i; j++) cout << s[j];
    cout << "\n";
    return true;
  }
  int j = 0;
  if (i == 0) j = 1;
  while (j < 10){
    s[i] = '0' + j;
    if (i < x - 1 && cs(i + 1)) return true; 
    else if (i >= x - 1 && mod(i + 1) == 0 && cs(i + 1)) return true;
    if (i == x - 1 && (i % 5 == 4)) j += 5;
    else if (i >= x - 1 && (i & 1)) j += 2;
    else j++;
  }
  return false;
}


void solve() {
  cin >> x >> y;  
  if (!cs()) cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  int testcase = 1;
  cin >> test;
  while (test--) {
    cout << "Case " << testcase++ << ": ";
    solve();
  }
}
