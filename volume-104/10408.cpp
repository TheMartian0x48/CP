// author: the__martian
// 10408
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

struct point{
  int x, y;
  point(int a,int b) { x = a, y = b;}
  bool operator<(const point& b){
    return x * 1.0 / y < b.x * 1.0 / b.y;
  }
};

void solve(int n, int k){

 vector<point> v{{1,1}};
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < i; j++) {
      if (__gcd(i, j) == 1)
        v.push_back({j, i});
    }
  }
  sort(all(v));
  
  cout << v[k -1].x << "/" << v[k - 1].y << "\n";

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, k;
  while (cin >> n >> k)
    solve(n, k);  
}
