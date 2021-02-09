
// author : the__martian
// 1225
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

vector<vi> data(10005, vi(10, 0));

void gen(){
  for (int i = 1; i <= 10000; i++) {
    int n = i;
    data[i] = data[i - 1];
    while (n) {
      data[i][n % 10]++;
      n /= 10;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  gen();
  int n; cin >> n;
  while (n--) {
    int t; cin >> t;
    for (int i = 0; i < 10; i++) {
      cout << data[t][i];
      if (i != 9)
        cout << " ";
    }
    cout << "\n";
  }
}