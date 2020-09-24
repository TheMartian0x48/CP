// @author: the__martian
// 10785
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

string c, v, s1, s2;
int n;
void solve() {
  int i = 0, j = 0;
  int flag = 1;
  while (sz(s1) + sz(s2) < n) {
    if (flag)
      s1 += v[j++];
    else 
      s2 += c[i++];
    flag = !flag;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for (char ch : "AUEOI"){
    v += string(21,  ch);
  }
  for (char ch : "JSBKTCLDMVNWFXGPYHQZR"){
    c += string(5, ch);
  }
  int t = 0, tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    cout << "Case " << ++t <<": ";
    s1 = "", s2="";
    solve();
    sort(all(s1));
    sort(all(s2));
    int i = 0, j = 0;
    while  (i < sz(s1) && j < sz(s2))
      cout << s1[i++] << s2[j++];
    if (i < sz(s1))
      cout << s1[i++];
    cout << "\n";
  }
}