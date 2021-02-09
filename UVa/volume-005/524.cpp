// @author: the__martian
// 524
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

vi prime{2,3,5,7,11,13,17,19,23,29,31};

vi used(20), v(20);

void solve(int n, int i = 1) {
  if (i == n) {
    if (binary_search(all(prime), v[0] + v[n - 1])) {
      rep(j,0,n) {
        if (j) cout  << " ";
        cout << v[j];        
      }
      cout << endl;
    }
    return;
  }

  rep(j,2,n + 1) {
    if (!used[j] && binary_search(all(prime), j + v[i - 1])) {
      v[i] = j;
      used[j] = 1;
      solve(n, i + 1);
      used[j] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, tt = 1;
  bool first = true;
  while (cin >> n) {
    rep(i,1,n + 1) used[i] = 0;
    v[0] = 1;
    if (!first)
      cout << "\n";
    first = false;
    cout << "Case " << tt++ << ":\n";
    solve(n);
  }
}