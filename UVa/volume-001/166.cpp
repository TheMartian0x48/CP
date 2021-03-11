/*
 * TheMartian0x48
 * 166
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
using vii = vector<long long>;
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
// ----------------

vi coins{5, 10, 20, 50, 100, 200};
unordered_map<int, int> mp;
int A, B, C, D, E, F, tar; 

void generate() {
  mp.clear();
  for (int a = 0 ; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {
        for (int d = 0; d <= D; d++) {
          for (int e = 0; e <= E; e++) {
            for (int f = 0; f <= F; f++) {
              int val = a * 5 + b * 10 + c * 20 + d * 50 + e * 100 + f * 200;
              int coin = a + b + c + d + e + f;
              if (val < tar || val > 2000) continue;
              auto it = mp.find(val);
              if (it == mp.end()) 
                mp[val] = coin;
              else 
                it->second = min(it->second, coin);
            }
          }
        }
      }
    }
  }
}
const int MAX = 10000;
vector<vi> dp(5000, vi(6, MAX));

int backtrack(int s, int i)  {
  if (i < 0) {
    return s == 0 ? 0 : MAX;
  }
  if (dp[s][i] == MAX) {
    int tmp = s, t = 0;
    while (tmp >= 0) {
      dp[s][i] = min(dp[s][i], t + backtrack(tmp, i - 1));
      tmp -= coins[i];
      t++;
    }
  }
  return dp[s][i];
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  double n;
  while(true) {
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
    if (!A && !B && !C && !D && !E && !F) break;
    scanf("%lf", &n);
    tar = (int)(n * 10000) / 100;
    
    generate();
    int res = INT_MAX;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second < res) {
        // cout << it->first << " " << it->second << endl;
        int tmp = backtrack(it->first - tar, 5) + it->second;
        res = min(res, tmp);
        // cout << tmp << endl;
      }
    }
    printf("%3d\n",res);
  }
}
