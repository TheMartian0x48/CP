// author : the__martian
// 12541 
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

struct Date{
  int yy, mm, dd;
  Date(){}
  Date(int _yy, int _mm, int _dd) : yy(_yy), mm(_mm), dd(_dd){}
  bool operator<(const Date& a){
    return yy < a.yy || (yy == a.yy && mm < a.mm) || (yy == a.yy && mm == a.mm && dd < a.dd);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string oldest, youngest;
  Date o, y;
  int n; cin >> n;
  string name; cin >> name;
  int dd, mm, yy; cin >> dd >> mm >> yy;
  o = Date(yy, mm, dd);
  y = o;
  oldest = youngest = name;
  for (int i = 0; i < n - 1; i++) {
    cin >> name >> dd >> mm >> yy;
    if (Date(yy, mm, dd) < o)
      oldest = name, o = Date(yy, mm, dd);
    if (y < Date(yy, mm, dd))
      youngest = name, y = Date(yy, mm, dd);
  }
  cout << youngest << "\n" << oldest << "\n";
}
