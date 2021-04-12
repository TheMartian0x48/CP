/*
 * TheMartian0x48
 * UVa 129
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
// clang-format 
string s = "";
int L, n;
void show() {
  int  i = 0;
  while(true) {
    for (int j = 0; j < 64; j++) {
      if (j && j % 4 == 0) {
        cout << " ";
      }
      cout << s[i++];
      if (i == sz(s)) break;
    }
    cout << "\n";
    if (i == sz(s)) break;
  }
  cout << s.size() << "\n";
}
bool cs() {
  if (n == 0) {
    show();
    return true;
  }
  for (char ch = 'A'; ch < 'A' + L; ch++) {
    s.push_back(ch);
    bool pp = false;
    for (int l = 1; l <= sz(s) / 2; l++) {
      int jj = sz(s) - 1;
      int kk = jj - l;
      bool same = true;
      for (int k = 0; k < l; k++) {
        if (s[jj] != s[kk]){
          same = false;
          break;
        }
        jj--, kk--;
      }
      if (same){
        pp = true;
        break;
      }
    }
    if (!pp && n-- && cs())  return true;
    s.pop_back();
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> L, n || L) {
    // cout << "--> " << t++ << endl;
    s.clear();
    if (!cs()) cout << "???\n";
  }
}
