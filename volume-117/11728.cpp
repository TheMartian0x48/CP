// author : the__martian
// 11728
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

int Sum(int n) {
  int tmp = 0;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      tmp += i;
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vi v(1005, -1);
  for (int i = 1; i < 1001; i++) {
    int tmp = Sum(i);
    if (tmp < 1001 && v[tmp] < i)
      v[tmp] = i;
  }

  int n, test = 1; 
  while (cin >> n, n) {
    cout << "Case " << test++ << ": " << v[n] << "\n";
  }
}
