
// author : the__martian
// 11489
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

  int tests; cin >> tests;
  for (int test = 1; test <= tests; test++) {
    cout << "Case " << test << ": ";
    string number; cin >> number;
    vi v(sz(number));
    int n = sz(number), sum = 0;
    for (int i = 0; i < n; i++){
      v[i] = number[i] - '0';
      sum += v[i];
    }

    bool player = true, moved = true;
    while (moved) {
      moved = false;
      for (int i = 0; i < n; i++) {
        if (v[i] >= 0 && (sum - v[i]) % 3 == 0) {
          sum -= v[i];
          moved = true;
          player = !player;
          v[i] = -1;
        }
      }
    }
    if (!player)
      cout << "S\n";
    else 
      cout << "T\n";
  }
}