// author : the__martian
// 11881 
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

int t;
vector<int> v(15);

int good(double r) {

  double res = 0;
  double d = 1 + r;
  for (int i = 1; i <= t; i++) {
    res += v[i] / d;
    d *= (1 + r);
  }
  if (res > v[0])
    return 1;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> t, t) {
    for (int i = 0; i <= t; i++)
      cin >> v[i];
    v[0] *= -1;

    double l = -1;
    double r = 1000;
    for (int i = 0; i < 100; i++) {
      double m = (l + r) / 2;
      int x = good(m);
      if (x > 0)
        l = m;
      else 
        r = m;
    }
    r = round(r * 100) / 100;
    printf("%.2lf\n", r);
  }
}
