
// author: the__martian
// 10340
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

  string a, b;
  while(cin >> a >> b) {
    int i = 0, j  = 0;
    while (i < sz(a) && j < sz(b)) {
      if (a[i] == b[j])
        i++;
      j++;  
    }
    if (i == sz(a))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
} 
