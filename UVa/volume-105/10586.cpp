// author : the__martian
// 10586 
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

struct term{
  int cof;
  int power;
  term(int c = 0, int p = 0) {
    cof = c;
    power = p;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, k;
  while (cin >> n >> k, n != -1 && k != -1) {
    vector<term> poly(n + 1);
    for (int i = 0; i <= n; i++) {
      int c;
      cin >> c;
      poly[i] = term(c, i);
    }
    vector<term> d;
    if ( k == 0) {
      cout << 0 << "\n";
      continue;
    } else {
      d.push_back(term(1, k));
      d.push_back(term(1, 0));
    }
    
    for (int i = n; i >= 0; i--) {
      if (poly[i].power < d[0].power)
        break;
      else {
        int p = poly[i].power - d[0].power;
        int c = poly[i].cof / d[0].cof;
        poly[p].cof -= c;
        poly[i].cof = 0;
      }
    }
    int i = n;
    while (i >= 0 && poly[i].cof == 0) {
      i--;
    }
    if (i == -1){
      cout << 0 << "\n";
    } else {
      for (int j = 0; j <= i; j++) {
        cout << poly[j].cof;
        if(j != i){
          cout << " ";
        } else {
          cout << "\n";
        }
      }
    }
  }
}
