/*
 * TheMartian0x48
 * UVa 10311
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
// clang-format on


const int P_MAX = 100000000;
bitset<P_MAX> _isprime;
vi primes;
int _upper_bound;

void generate_prime(int upper_bound) {
  _upper_bound = upper_bound;
  _isprime.set(); _isprime[0] = _isprime[1] = 0;
  for (int i = 4; i <= upper_bound; i += 2) _isprime[i] = 0;
  for (ll i = 3; i * i <= upper_bound; i += 2) { 
    if (_isprime[i])
      for (ll j = i * i; j <= upper_bound; j += i) 
        _isprime[j] = 0;
  }
  for (int i = 2; i <= upper_bound; i++) 
    if (_isprime[i]) primes.push_back(i);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  generate_prime(P_MAX-1);
  // cout << primes.size() << endl;
  int m = primes.size();
  int n;
  while(cin >> n) {
    if (n < 5 || ((n & 1) && _isprime[n - 2] == false)) {
      cout << n << " is not the sum of two primes!\n";
      continue;
    }
    if (n & 1) {
      cout << n << " is the sum of " << 2 << " and " << n - 2 << ".\n";
      continue;
    }
    int i = lower_bound(all(primes), n / 2) - primes.begin();
    int j = i--;
    while (i >= 0 && j < m) {
      if (primes[i] + primes[j] > n) i--;
      else if (primes[i] + primes[j] < n) j++;
      else {
        break;
      }
    }
    if (i < 0 || j >= m) cout << n << " is not the sum of two primes!\n";
    else cout << n << " is the sum of " << primes[i] << " and " << primes[j] << ".\n";
  }
}
