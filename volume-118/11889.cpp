
// author : the__martian
// 11889
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

long _sieve_size = 10000000;
bitset<10000005> sieve;
vector<long> primes;

void Sieve(long long n = 1e6){
  _sieve_size = n + 1;
  sieve.set();
  sieve.reset(0), sieve.reset(1);
  for (long long i = 2; i < _sieve_size; i++) {
    if (sieve[i]) {
      for (long long j = i * i; j < _sieve_size; j += i){
        sieve.reset(j);
      }
      primes.push_back(i);
    }
  }
}


vector<pair<int, int>> PrimeFactor(long long n){
  vector<pair<int, int>> tmp;
  for (auto p : primes) {
    if (n % p) continue;
    int c = 0;
    while (n % p == 0) {
      c++;
      n /= p;
    }
    tmp.push_back({p, c});
    if (n == 1) break;
  }
  if (n > 1)
    tmp.push_back({n, 1});
  return move(tmp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Sieve(1e4);
  int test; cin >> test;
  while (test--){
    ll a, c; cin >> a >> c;
    auto af = PrimeFactor(a);
    auto cf = PrimeFactor(c);
    bool flag = true;
    ll b = 1;
    int i = 0, j = 0;

    while (i < sz(af) && j < sz(cf)) {
      if (af[i].first == cf[j].first){
        if (af[i].second > cf[j].second){
          flag = false;
          break;
        } else if (af[i].second < cf[j].second){
          b *= pow(cf[j].first * 1LL, cf[j].second * 1LL);
        }
        i++, j++;
      } else if (cf[j].first < af[i].first){
        b *= pow(cf[j].first * 1LL, cf[j].second * 1LL);
        j++;
      } else {
        flag = false;
        break;
      }
      if (b > c){
        flag = false;
        break;
      }
    }
    if (i < sz(af)){
      flag = false;
    }
    while (j < sz(cf)){
      b *= pow(cf[j].first * 1LL, cf[j].second * 1LL);
      if (b > c){
        flag = false;
        break;
      }
      j++;
    }

    if (flag) {
      cout << b << "\n";
    } else {
      cout << "NO SOLUTION\n";
    }
  }
}