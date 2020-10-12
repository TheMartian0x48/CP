
// author : the__martian
// 11995
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
  while (cin >> n) {
    priority_queue<int> pq;
    stack<int> st;
    queue<int> q;
    bool is_pq = true, is_st = true, is_q = true;
    int a, b;
    while(n--) {
      cin >> a >> b;
      if (a == 1) {
        if (is_pq)
          pq.push(b);
        if (is_st)
          st.push(b);
        if (is_q)
          q.push(b);
      } else {
        if (is_pq) {
          if (pq.empty() || pq.top() != b) {
            is_pq = false;
          } else {
            pq.pop();
          }
        }

        if (is_q) {
          if (q.empty() || q.front() != b) {
            is_q = false;
          } else {
            q.pop();
          }
        }

        if (is_st) {
          if (st.empty() || st.top() != b) {
            is_st = false;
          } else {
            st.pop();
          }
        }
      }
    }
    int c = is_pq + is_q + is_st;
    if (c > 1) {
      cout << "not sure\n";
    } else if (c == 1) {
      if (is_st)
        cout << "stack\n";
      else if (is_q)
        cout << "queue\n";
      else 
        cout << "priority queue\n";
    } else {
      cout << "impossible\n";
    }
  }
}