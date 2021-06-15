
/*
 * TheMartian0x48 
 * USACO 2019 February Contest, Gold
 * Problem 2. Dishwashing
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
void usaco(string s) {freopen((s + ".in").c_str(), "r", stdin );freopen((s + ".out").c_str(), "w", stdout );}
// clang-format on

vector<vector<int>*> mystack;
int cur_size = 0;

int index(int x) {
  int l = -1, r = cur_size;
  while(l + 1 < r) {
    int m = (l + r) / 2;
    if (mystack[m]->back() < x) l = m;
    else r = m;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  usaco("dishes");
  int n; cin >> n;
  vector<int> v(n);
  re(v);
  mystack.resize(n);
  stack<int> res;
  
  for (int i = 0; i < n; i++) {
    if (res.size() && res.top() > v[i]) break;
    int id = index(v[i]);
    if (id && mystack[id - 1]->front() > v[i]) {
      id--;
    } else if (mystack[id] == nullptr) {
      mystack[id] = new vector<int>();
      mystack[id]->push_back(v[i]);
      cur_size++;
      continue;
    }
    if (mystack[id]->back() < v[i]) {
      for (int j = 0; j < id; j++) {
        for (int k = mystack[j]->size() - 1; k >= 0; k--) {
          res.push(mystack[j]->at(k));
        }
        delete mystack[j];
        mystack[j] = nullptr;
      }
      vector<int> &tmp = *mystack[id];
      while (tmp.size() && tmp.back() < v[i]) {
        res.push(tmp.back());
        tmp.pop_back();
      }
      for (int k = 0, j = id; j < cur_size; j++, k++) {
        mystack[k] = mystack[j];
      }
      cur_size -= id;
      id = 0;
    }
    mystack[id]->push_back(v[i]);
  }
  for (int i = 0; i < cur_size; i++) {
    vector<int>&tmp = *mystack[i];
    while (res.empty() || (tmp.size() && tmp.back() > res.top())) {
      res.push(tmp.back());
      tmp.pop_back();
    }
  }
  cout << res.size();
}
