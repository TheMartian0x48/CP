// author: the__martian
// 377
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

unordered_map<char, int> dig;

ll RotateR(ll a){
  return a / 4;  
}

ll RotateL(ll a){
  return a * 4;
}

string Answer(ll a){
  string s;
  while (a) {
    int d = a %  4;
    a /= 4;
    if (d == 0)
      s += 'V';
    else if (d == 1)
      s += 'U';
    else if (d == 2)
      s += 'C';
    else 
      s += 'D';
  }
  while (sz(s) < 8)
    s += 'V';
  reverse(all(s));
  return s;

}

ll Add(ll a, ll b){
  return a + b;
}

ll ToLL(string s){
  ll tmp = 0, f = 1;
  for (int i = sz(s) - 1; i >= 0; i--){
    tmp += f * (dig[s[i]]);
    f *= 4;
  }
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  dig['V'] = 0, dig['U'] = 1, dig['C'] = 2, dig['D'] = 3;

  cout << "COWCULATIONS OUTPUT\n";
  int t;cin >> t;
  while (t--){
    string num1, num2; cin >> num1 >> num2;
    ll a = ToLL(num1), b = ToLL(num2);
    rep(i,0,3){
      char ch; cin >> ch;
      if (ch == 'R')
        b = RotateR(b);
      else if (ch == 'L')
        b = RotateL(b);
      else if (ch == 'A')
        b = Add(a, b);
    }
    num2 = Answer(b);
    string r; cin >> r;
    if (r == num2)
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
  cout << "END OF OUTPUT\n";
}