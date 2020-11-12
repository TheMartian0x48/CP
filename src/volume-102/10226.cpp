// author : the__martian
// 10226 
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

  int t; 
  string tmp; getline(cin, tmp);
  t = stoi(tmp);
  getline(cin, tmp);
  while (t--) {
    map<string, int> mp;
    double n = 0;
    while (getline(cin, tmp)) {
      if (tmp == "")
        break;
      mp[tmp]++;
      n++;
    }
    double f = 100 / n;
    for (auto &p : mp) {
      printf("%s %.4lf\n", p.first.c_str(), p.second * f);
    }

    if (t)
      printf("\n");
  }
}
