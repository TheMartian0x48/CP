/*
 * TheMartian0x48
 * UVa 897
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


const int P_MAX = 1000;
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

bool isprime(ll n) {
  if (n <= _upper_bound) return _isprime[n];
  for (auto p : primes) {
    if ( (long long)p * p > n) return true;
    else if (n % p == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  generate_prime(P_MAX - 1);
  vector<int> v;
  for (auto p : primes) {
    string s = to_string(p);
    sort(all(s));
    bool pri = true;
    do {
      pri = isprime(stoi(s));
    } while(pri && next_permutation(all(s)));
    if (pri) v.push_back(p);
  }
  int n;
  while (cin >> n, n) {
    int t = upper_bound(all(v), n) - v.begin();
    int res;
    if (t == sz(v) || v[t] >= (int)pow(10, (int)log10(n) + 1))
      res = 0;
    else res = v[t];
    cout << res << "\n";
  }
}
