/*
 *TheMartian0x48
 */

/*

Problem: https://www.codechef.com/FEB21C/problems/PRIGAME
Solution: https://www.codechef.com/viewsolution/42490039
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
using pii = pair<int, int>;
using vi = vector<int>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

// ---------------- (* Extract here *)
// -----------------
ll _sieve_size;
bool _has_sieved = false;
bitset<10000010> sieve;
vector<int> primes;
void generate_prime(int n = 1000000) {
  _sieve_size = n + 1;
  sieve.set();
  sieve.reset(0), sieve.reset(1);
  for (ll i = 2; i <= n; i++) {
    if (sieve[i]) {
      primes.push_back((int)i);
      for (ll j = i * i; j <= n; j += i) {
        sieve[j] = 0;
      }
    }
  }
  _has_sieved = true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  generate_prime(1000005);
  vector<int> pc(1000005, 0);
  for (int i = 2; i < 1000005; i++) {
    pc[i] += pc[i - 1];
    if (sieve[i]) pc[i]++;
  }
  
  int test; 
  cin >> test;
  while(test--) {
    int x, y;
    cin >> x >> y;
    if (pc[x] <= y) {
      cout << "Chef\n";
    } else {
      cout << "Divyam\n";
    }
  }
}
