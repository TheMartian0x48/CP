// @author: the__martian
// 11634

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

const int N = 10005;
bitset<N> bt;

ll generate(ll n) {
  n *= n;
  int i = 0;
  while (n && i < 2) {
    i++;
    n /= 10;
  }
  return n % 10000;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll n;
  while (cin >> n, n) {
    int c = 1;
    bt.reset();    
    bt.set(n);
    while (true) {
      n = generate(n);
      if (bt[n]) break;
      bt.set(n);
      c++;
    }

    cout << c << "\n";
  }
}