
// author: the__martian
// 11955
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

  vector<vector<ll>> bino(55, vector<ll>(55, 1));
  for (int i = 2; i < 51; i++) {
    for (int j = 1; j < i; j++) {
      bino[i][j] = bino[i - 1][j] + bino[i - 1][j - 1];
    }
  }

  int t; cin >> t;
  rep(test, 1, t + 1){
    cout << "Case " << test << ": ";
    string s, a, b, delim="(+)^";
    cin >> s;
    int p;

    stringstream ss(s);
    getline(ss, s, '(');
    getline(ss, a, '+');
    getline(ss, b, ')');
    getline(ss, s, '^');
    ss >> p;
     
    cout << a;
    if (p > 1)
      cout << "^" << p;
    rep(i,1,p){
      cout << "+" << bino[p][i] << "*" << a;
      if (i != p - 1){
        cout << "^" << p - i;
      }
      cout <<"*" << b;
     if (i != 1){
       cout <<"^" << i;
     }
    }
    cout << "+" << b;
    if (p > 1)
      cout << "^" << p;
    cout <<"\n";
  }
}
