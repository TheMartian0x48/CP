// author : the__martian
// 12210
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

  int g, b, tmp;
  int test = 1;
  vi boys(10000), girls(10000);
  while (cin >> b >> g, b || g) {

    for (int i = 0; i < b; i++) {
      cin >> tmp;
      boys[i] = tmp;
    }

    for (int i = 0; i < g; i++) {
      cin >> tmp;
      girls[i] = tmp;
    }

    if (g >= b) {
      cout << "Case " << test++ << ": " << 0;
      cout << "\n";
      continue;
    }

    sort(boys.begin(), boys.begin() + b);
    sort(girls.begin(), girls.begin() + g);

    cout << "Case " << test++ << ": " << b - g << " " << boys[0] << "\n";

  }
}
