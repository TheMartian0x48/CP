// @author: the__martian
// 294
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


int _sieve_size;
bitset<10000000> sieve;
vector<long long> prime;

void Sieve(long long n = 1e6) {
  _sieve_size = n + 1;
  sieve.set(); sieve.reset(0), sieve.reset(1);
  for (long long i = 2; i < _sieve_size; i++) {
    if (sieve[i]) {
      for (long long j = i * i; j < _sieve_size; j += i) {
        sieve.reset(j);
      }
      prime.push_back(i);
    }
  }
}

bool IsPrime(long long n) {
  if (n < _sieve_size)
    return sieve[n];
  for (int i = 0; i < (int) prime.size() && prime[i] * prime[i] <= n; i++)
    if (n % prime[i] == 0) return false;
  return true;
}


vector<long long> PrimeFactor(long long n) {
  vector<long long> res;
  for (int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= n; i++) {
    while (n % prime[i] == 0)
      res.push_back(prime[i]), n /= prime[i];
  }
  if (n > 1) res.push_back(n);
  return move(res);
}

ll fac(ll n) {
  ll res = 1;
  for (auto p : prime) {
    if (p > n) break;
    ll c = 0;
    while (n % p == 0) c++, n /= p;
    res *= (c + 1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Sieve();

  int t; cin >> t;
  vi v(10005);
  while (t--) {
    ll l, u, d; cin >> l >> u;
    d = u - l + 1;
    ll res = 0, c = 0;
    for (ll i = 0; i < d; i++) {
      v[i] = fac(l + i);
      if (v[i] > c) {
        c = v[i];
        res = max(res, i + l);
      }
    }
    cout << "Between "<< l << " and " << u << ", " << res << " has a maximum of " << c << " divisors." << endl;
  }
}
