#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n; // array size

// Max size of tree
int tree[2 * N];

// function to build the tree
void build(int arr[])
{
  // insert leaf nodes in tree
  for (int i = 0; i < n; i++)
    tree[n + i] = arr[i];

  // build the tree by calculating parents
  for (int i = n - 1; i > 0; --i)
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

// function to update a tree node
void updateTreeNode(int p, int value)
{
  // set value at position p
  tree[p + n] = value;
  p = p + n;

  // move upward and update parents
  for (int i = p; i > 1; i >>= 1)
    tree[i >> 1] = tree[i] + tree[i ^ 1];
}

// function to get sum on interval [l, r)
int query(int l, int r)
{
  int res = 0;

  // loop to find the sum in the range
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
      res += tree[l++];

    if (r & 1)
      res += tree[--r];
  }

  return res;
}



vector<int> sieve(int n) {
  vector<int> p(n + 1, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i < p.size(); i++) {
    if (p[i] == 0) {
      continue;
    }
    for (int j = 0; i * i + i * j < p.size(); j++) {
      p[i * i + i * j] = 0;
    }
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> ps = sieve(sqrt(n) + 1);
    vector<long long> ans = {n};
    for (int i = 0; i < ps.size(); i++) {
      if (ps[i] == 0) {
        continue;
      }
      vector<long long> tmp;
      long long nc = n;
      while (nc % i == 0) {
        long long nxt = nc / i;
        if (nxt % i > 0) {
          break;
        }
        tmp.push_back(i);
        nc = nxt;
      }
      tmp.push_back(nc);
      if (tmp.size() > ans.size()) {
        ans = tmp;
      }
    }
    cout << ans.size() << endl;
    for (auto val: ans) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
