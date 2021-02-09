
// author: the__martian
// 10718
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
  
  uint32_t n, l, u;
  while (cin >> n >> l >> u){
    uint32_t m = ~n;    
    for (int i = 31; i >= 0; i--) {
      if ((l & (1 << i)) == (u & (1 << i))){
        if(l & (1 << i))
          m |= (1<<i);
        else 
          m &= ~(1<<i);
      } else {
        break;
      }
    }
    if (m > u){
      int i = log2(u);
      while (m > u) {
        if ((u & (1<<i)) == false) {
          m &= ~(1<<i);
        }
        i--;
      }
    } else if (m < l){
      int i = log2(l);
      while (l > m){
        if (l & (1 << i)){
          m |= (1<<i);
        }
        i--;
      }
    }
    cout << m << "\n";
  }
}
