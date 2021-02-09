// @author: the__martian
// 10139
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

long long _sieve_sz;
bitset<100001> _sieve;
vector<ll> primes;

void Sieve(long long n = 1e6) {
  _sieve_sz = n+1;
  _sieve.set();
  _sieve[0] = _sieve[1] = 0;
  for (long long i = 2; i * i < _sieve_sz; i++) {
    if (_sieve[i])
      for (long long j = i * i; j < _sieve_sz; j += i)
        _sieve[j] = 0;
  }
  for (ll i = 2; i < _sieve_sz; i++)
    if (_sieve[i]) primes.push_back(i);
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  Sieve(100001);
  
  ll n, a;
  while (cin >> n >> a) {

    if (a == 0 || n >= a) {
      cout << a << " divides " << n << "!\n";
      continue;
    } else if (n == 0) {
      if (a == 1) {
        cout << "1 divides 0!\n";
      } else {
        cout << a << " does not divide 0!\n";
      }
      continue;
    }
    
    vector<pair<ll, ll>> fac;
    int c;
    ll m = a;
    for (auto p : primes) {
      c = 0;
      if (p > m) break;
      while (m % p == 0) {
        c++;
        m /= p;
      }
      if (c)
        fac.push_back({p, c});
    }
    if (m > 1) {
      fac.push_back({m, 1});
    }

    bool sol = true;
    for (auto pp : fac) {
      c = 0;
      ll p = pp.first;
      while (p <= n) {
        c += n / p;
        p *= pp.first;
      }
      if (c < pp.second) {
        sol = false;
        break;
      }
    }
    if (sol) {
      cout << a << " divides " << n << "!\n";
    } else {
      cout << a << " does not divide " << n << "!\n";
    }
  }
}