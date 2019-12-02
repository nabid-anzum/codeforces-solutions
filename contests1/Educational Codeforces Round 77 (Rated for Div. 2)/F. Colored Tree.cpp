#include <bits/stdc++.h>
using namespace std;
 
#define dbg(x) #x << " = " << (x) << " | " <<
 
#define int int64_t
#define fi first
#define se second
 
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
 
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
const int N = 1e5 + 43;
const int M = 1e9 + 7;
 
int add(int x, int y) { return (x += y) < M ? x : x - M; }
int sub(int x, int y) { return (x -= y) < 0 ? x + M : x; }
 
int n;
int l[N];
int r[N];
vector<int> adj[N];
 
int d[N];
int sz[N];
int inv[N];
int ft[N][2];
 
int sol = 0;
int numoftrees = 1;
 
void addft(int p, int v) {
  for (int i = p + 5; i < N; i += i & -i) {
    ft[i][0] = add(ft[i][0], v);
    ft[i][1] = sub(ft[i][1], (p - 1) * v % M);
  }
}
 
int queryft(int p) {
  int ret = 0;
  for (int i = p + 5; i > 0; i -= i & -i) {
    ret = add(ret, ft[i][0] * p % M);
    ret = add(ret, ft[i][1]);
  }
  return ret;
}
 
void upd(int x, int sgn) {
  int val = numoftrees * inv[r[x] - l[x] + 1] % M;
  addft(l[x], sgn ? M - val : val);
  addft(r[x] + 1, sgn ? val : M - val);
}
 
int get(int x) {
  return inv[r[x] - l[x] + 1] * sub(queryft(r[x]), queryft(l[x] - 1)) % M;
}
 
void dfsinit(int x) {
  sz[x] = 1;
  for (int &y : adj[x]) {
    adj[y].erase(find(all(adj[y]), x));
    d[y] = d[x] + 1;
    dfsinit(y);
    sz[x] += sz[y];
    if (sz[y] > sz[adj[x][0]]) {
      swap(y, adj[x][0]);
    }
  }
}
 
vector<int> dfs(int x) {
  vector<vector<int>> subtrees = {{x}};
  for (int i = 1; i < sz(adj[x]); ++i) {
    subtrees.push_back(dfs(adj[x][i]));
    for (int y : subtrees.back()) {
      upd(y, 1);
    }
  }
  vector<int> ret;
  if (sz(adj[x])) {
    ret = dfs(adj[x][0]);
  }
  int cnt = 0;
  for (vector<int> &tree : subtrees) {
    for (int y : tree) cnt = add(cnt, get(y));
    for (int y : tree) upd(y, 0);
    ret.insert(ret.end(), all(tree));
  }
  sol = sub(sol, d[x] * 2 * cnt % M);
  return ret;
}
 
void task() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    inv[i] = (M - M / i) * inv[M % i] % M;
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    (numoftrees *= r[i] - l[i] + 1) %= M;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfsinit(1);
  for (int i = 1; i <= n; ++i) {
    upd(i, 0);
  }
  for (int i = 1; i <= n; ++i) {
    upd(i, 1);
    sol = add(sol, d[i] * get(i) % M);
    upd(i, 0);
  }
  for (int i = 1; i <= n; ++i) {
    upd(i, 1);
  }
  dfs(1);
  cout << sol << '\n';
}
 
main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) task();
}
