// @author: the__martian
// 543
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

const ll N = 1e6;
bitset<N> bt;

vi prime;

void Prime(){
  bt.set();
  bt.reset(0), bt.reset(1);
  for (ll i = 2; i < N; i++) {
    if (bt[i]) {
      for (ll j = i * i; j < N; j += i) {
        bt.reset(j);
      }
      prime.push_back(i);
    }
  }
  bt.reset(2);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  Prime();
  ll n;
  while (cin >> n, n) {
    ll a = 0, b = 0;
    for (int i = 1; prime[i] * 2 <= n; i++) {
      if (bt[n - prime[i]]) {
        a = prime[i], b = n - prime[i];
        break;
      }
    }
    if (a) {
      cout << n << " = " << a << " + " << b << "\n";
    } else {
      cout << "Goldbach's conjecture is wrong.\n";
    }
  }
}