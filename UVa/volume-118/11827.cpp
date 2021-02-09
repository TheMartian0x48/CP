
// author: the__martian
// 11827
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
  vi v(105);
  string s; getline(cin, s);
  int t = stoi(s);
  while (t--){
    getline(cin, s);
    stringstream ss(s);
    int n = 0;
    while (ss >> v[n])
      n++;
    int res = 0;
    for  (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        res = max(res, __gcd(v[i], v[j]));
    cout << res << "\n";
  }

}
