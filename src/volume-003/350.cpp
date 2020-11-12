// @author: the__martian
// 350
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  vi v(10000);
  int z, i, m, l, tt = 1;
  while (cin >> z >> i >> m >> l, z || i || m || l) {
    rep(j,0,10000)
      v[j] = 0;
    
    int s = 1;
    int n;
    while (true) {
      n = (z * l + i) % m;
      if (v[n]) {
        s -= v[n];
        break;
      }
      v[n] = s++;
      l = n;
    }
    cout << "Case " << tt++ << ": " << s << "\n";
  }
}