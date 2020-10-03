
// author: the__martian
// 10042
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

int digitsum(ll n){
  int  s = 0;
  while (n){
    s += n % 10;
    n /= 10;
  } 
  return s;
}

ll PrimeFactor(long long n) {
  ll res = 0;
  ll m = n;
  if (n < _sieve_size && sieve[n]) return -1;
  for (int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= n; i++) {
    if (n % prime[i]) continue;
    int s = digitsum(prime[i]);
    while (n % prime[i] == 0){
      n /= prime[i];
      res += s;
    }
  }
  if (n == m) return -1;
  if (n > 1) res+= digitsum(n);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  Sieve();

  int tt; cin >> tt;
  while (tt--){
    ll n; cin >> n;
    int s, t;
    n++;
    while (true) {
      s = digitsum(n);
      t = PrimeFactor(n);
      if (s == t) break;
      else n++;
    }
    cout << n << "\n";
  }
} 
