// author : the__martian
// 11760 
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

  vector<pii> v(2005);
  int r, c, n, test = 1;
  while (cin >> r >> c >> n) {
    if (!r && !c && !n) break;
    cout << "Case " << test++ << ": ";
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }
    int rr, cc; cin >> rr >> cc;
    bool left = cc - 1 >= 0, right = cc + 1 < c, stand = true;
    bool upper = rr - 1 >= 0, lower = rr + 1 < r;

    for (int i = 0; i < n; i++) {
      if (v[i].first == rr)
        left = right = stand = false;
      if (v[i].first == rr - 1)
        upper = false;
      if (v[i].first == rr + 1)
        lower = false;
      if (v[i].second == cc)
        upper = lower = stand = false;
      if (v[i].second == cc - 1)
        left = false;
      if (v[i].second == cc + 1)
        right = false;
    }

    if (left || right || upper || lower || stand)
      cout << "Escaped again! More 2D grid problems!\n";
    else 
      cout << "Party time! Let's find a restaurant!\n";
  }
}
