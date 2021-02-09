
// author : the__martian
// 12592
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

  int n; cin >> n;
  unordered_map<string, string> mp;
  string a, b; getline(cin, a);
  while (n--){
    getline(cin, a);
    getline(cin, b);
    mp[a] = b;
  }
  int q; cin >> q; getline(cin, a);
  while (q--) {
    getline(cin, a);
    cout << mp[a] << "\n";
  }
}