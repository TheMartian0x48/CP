// @author: the__martian
// 681
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
vector<ll> prime;
vector<ll> factor(N);
void Prime() {
  bt.set();
  bt.reset(0), bt.reset(1);
  for (ll i = 2; i < N; i++) {
    if (bt[i]) {
      prime.push_back(i);
      for (ll j = i * i; j < N; j += i)  {
        bt.reset(j);
      }
    }
  }
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  Prime();

  string s;
  while (getline(cin, s), s != "0") {
    stringstream ss(s);
    ll n = 1, a, b;
    while (ss >> a >> b) {
      n *= pow(a, b);
    }
    n--;
    int i = -1;
    while (n > 1) {
      ++i;
      ll p = prime[i];
      factor[i] = 0;
      while (n % p == 0) {
        factor[i]++;
        n /= p;
      }      
    }
    bool f = true;
    while (i >= 0) {
      if (factor[i] == 0) {
        i--;
        continue;
      }
      if (!f) cout << " ";
      f = false;
      cout << prime[i] << " " << factor[i];
      i--;
    }
    cout << "\n";
  }
}