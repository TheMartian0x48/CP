
// author: the__martian
// 11371
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

  string s;
  while (cin >> s) {
    sort(s.rbegin(), s.rend());
    ll a = stoll(s);
    reverse(all(s));
    int i = 0;
    while (s[i] == '0')
      i++;
    swap(s[0], s[i]);
    ll b = stoll(s);
    ll d = a - b;
    cout << a << " - " << b << " = " << d << " = 9 * " << d / 9 << "\n";
  }
}
