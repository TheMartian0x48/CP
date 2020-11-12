// author : the__martian
// 10038 
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

  int n;
  vector<bool> hash(3005);
  while (cin >> n) {
    hash.assign(n, false);
    int a, b; cin >> a;
    for (int i = 1; i < n; i++) {
      cin >> b; hash[abs(b - a)] = true;
      a = b;
    }
    bool sol = true;
    for (int i = 1; i < n; i++) {
      sol = sol && hash[i];
    }
    cout << (sol ? "Jolly" : "Not jolly") << "\n";
  }
}
