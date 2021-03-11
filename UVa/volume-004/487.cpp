/*
 *TheMartian0x48
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

unordered_set<string> dict;
vector<string> g(25);
int n;
string word;

vi dr{-1, -1, -1, 0, 0, 1, 1, 1};
vi dc{-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j) {
  word += g[i][j];
  g[i][j] = '.';
  if (word.size() > 2) dict.insert(word);
  for (int k = 0; k < 8; k++) {
    int r = i + dr[k], c = j + dc[k];
    if (r >= 0 && r < n && c >= 0 && c < n && g[r][c] != '.' && g[r][c] > word.back()) {
      dfs(r, c);
    }
  }
  g[i][j] = word.back();
  word.pop_back();
}
bool cmp(const string &item1, const string& item2) {
  if (item1.size() < item2.size()) return true;
  else if (item2.size() == item1.size()) return item1 <= item2;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<string> wordlist;

  int t; 
  cin >> t;
  while(t--) {
    cin >> n;
    rep(i,0,n) cin >> g[i];
    word.clear();
    dict.clear();
    wordlist.clear();
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++)
        dfs(i, j);
    
    for (auto a : dict) wordlist.push_back(a);
    sort(all(wordlist), cmp);
    for (auto a : wordlist)
      cout << a << "\n";

    if(t) cout << "\n";
  }
}