
// author: the__martian
// 11287
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

ll power(ll a, ll p, ll m){
  if (p == 0)
    return 1;
  ll t = power(a, p / 2, m);
  t = (t * t) % m;
  if (p % 2)
    return (t * a) % m;
  return t;
}


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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  Sieve(1e5);
  ll p, a;
  while (cin >> p >> a, p != 0 && a != 0) {
    ll r = power(a, p, p);
    bool pr = IsPrime(p);
    cout << (r == a && pr == false ? "yes" : "no") << "\n";
  }
}
