// @author: the__martian
// 10738
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N = 1e6+5;
  vi v(N), b(N, 0);
  rep(i,0,N)
    v[i] = i;

  for (ll i = 2; i < N; i++) {
    if (v[i] == i) {
      for (ll j = i * 2; j < N; j += i)
        v[j] /= i, b[j]++;
      v[i] = -1;
    } else if (v[i] == 1) {
      v[i] = b[i] % 2 ? -1 : 1;
    } else {
      v[i] = 0;
    }
    v[i] += v[i - 1];
  }
  
  int n; 
  while (scanf("%d", &n), n){
    printf("%8d%8d%8d\n", n, v[n] - v[n - 1], v[n]);
  }
}
