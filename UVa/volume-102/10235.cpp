// @author: the__martian
// 10235
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

void Sieve(long long n = 1e6) {
  _sieve_size = n + 1;
  sieve.set(); sieve.reset(0), sieve.reset(1);
  for (long long i = 2; i  * i <= _sieve_size; i++) {
    if (sieve[i]) {
      for (long long j = i * i; j < _sieve_size; j += i) {
        sieve.reset(j);
      }
    }
  }
}

bool IsPrime(long long n) {
    return sieve[n];
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  Sieve();
  ll p;
  while (cin >> p){
    if (IsPrime(p)){
      cout << p;
      ll m = 0, n = p;
      while (n) m *= 10, m += n % 10, n /= 10;
      if (m != p && IsPrime(m)){
        cout << " is emirp.\n";
      } else {
        cout << " is prime.\n";
      }

    } else {
      cout << p << " is not prime.\n";
    }
  }
}
