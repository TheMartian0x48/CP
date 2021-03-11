/*
 * TheMartian0x48
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
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

struct Node{
  int val;
  Node *left, *right;
  Node(int x) {
    val = x;
    left = right = nullptr;
  }
};

struct BST{
  Node *root = nullptr;
  void insert(int v) {
    root = insert(v, root);
  }
  Node* insert(int v, Node* ptr) {
    if (ptr == nullptr) 
      return new Node(v);
    if (ptr->val > v) ptr->left = insert(v, ptr->left);
    else ptr->right = insert(v, ptr->right);
    return ptr;
  }
  bool same(Node* ptr) {
    return same(root, ptr);
  }
  bool same(Node*ptr1, Node* ptr2) {
    if ((ptr1 && !ptr2) || (!ptr1 && ptr2))
      return false;
    else if (!ptr1 && !ptr2) return true;
    return same(ptr1->left, ptr2->left) and same(ptr1->right, ptr2->right);
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  while(cin >> n >> k) {
    vector<BST> v(n);
    int a;
    rep(i,0,n) {
      rep(j,0,k) {
        cin >> a;
        v[i].insert(a);
      }
    }
    vi same(n, 1);
    int res = 0;
    rep(i,0,n) {
      if (same[i] == 0) {
        continue;
      }
      res++;
      same[i] = 0;
      rep(j,i + 1,n) {
        if (v[i].same(v[j].root)) 
          same[j] = 0;
      }
    }
    cout << res << "\n";
  }
}
