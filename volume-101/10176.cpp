// @author: the__martian
// 10176
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  ll p = 131071;
  string str;
  while (cin >> str) {
    string s = str;
    while (str[sz(str) - 1] != '#') {
      cin >> str;
      s += str;
    }
    int i = sz(s) - 2;
    ll tmp = 0;
    ll f = 1;
    while (i >= 0) {
      tmp += f * (s[i] - '0');
      tmp %= p;
      f = (f * 2) % p;
      i--;
    }
    cout << (tmp ? "NO\n" : "YES\n");
  }
}