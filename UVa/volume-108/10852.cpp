/*
 * TheMartian0x48
 * UVa 10852
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

  generate_prime(10001);
  
  int m = primes.size();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int j = lower_bound(all(primes), n) - primes.begin();
    if (j == m || primes[j] > n) j--;
    int mx = INT_MIN;
    int res = 0;
    while (j >= 0) {
      int x = primes[j--];
      int p = n / x;
      if (mx < n - p * x) mx = n - p * x, res = x;
    }
    cout << res << "\n";
  }
}
