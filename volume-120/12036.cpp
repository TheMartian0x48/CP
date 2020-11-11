// author : the__martian
// 12036 
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
    int n; cin >> n;
    unordered_map<int, int> mp;
    bool sol = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int tmp; cin >> tmp;
        mp[tmp]++;
        if (mp[tmp] > n)
          sol = false;
      }
    }
    cout << (sol ? "yes" : "no") << "\n";
  }
}
