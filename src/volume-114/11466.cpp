// @author: the__martian
// 11466
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
bitset<10000005> sieve;
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


ll PrimeFactor(long long n) {
  ll c = 0, l;
  
  for (auto p : prime) {
    if (n % p) continue;
    c++;
    l = p;
    while (n % p == 0)
      n /= p;
    if (n == 1) break;
  }
  if (n > 1) c++;
  return c > 1 ? max(l, n) : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  Sieve(10000000);
  ll n;
  while (cin >> n, n) {
    cout << PrimeFactor(abs(n)) << "\n";
  }
}
