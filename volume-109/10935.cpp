// author : the__martian
// 10935 
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

  int n; 
  while (cin >> n, n)  {
    queue<int> q;
    for (int i = 1; i <= n;i++) {
      q.push(i);
    }
    cout << "Discarded cards:";
    if (q.size() > 1)
      cout << " ";
    while (q.size() > 1) {
      cout << q.front(); q.pop();
      int t = q.front(); q.pop();
      q.push(t);
      if (q.size() > 1)
        cout << ", ";
    }
    cout << "\nRemaining card: " << q.front() << "\n";    
  }
}
