// @author: the__martian
// 443
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  vector<ll> v(6000);
  v[1] = 1;
  int two = 1, three = 1, five = 1, seven = 1;
  for (int i = 2; i < 5843; i++) {
    ll a = v[two] * 2;
    ll b = v[three] * 3;
    ll c = v[five] * 5;
    ll d = v[seven] * 7;
    v[i] = min(a, min(b, min(c, d)));
    if (a == v[i]) two++;
    if (b == v[i]) three++;
    if (c == v[i]) five++;
    if (d == v[i]) seven++;    
  }

  int n;
  while (cin >> n, n) {
    cout << "The " << n;
    if (n % 10 == 1 && n % 100 != 11)
      cout << "st";
    else if (n % 10 == 2 && n % 100 != 12)
      cout << "nd";
    else if (n % 10 == 3 && n % 100 != 13)
      cout << "rd";
    else 
      cout << "th";
    cout << " humble number is " << v[n] << ".\n";
  }
}