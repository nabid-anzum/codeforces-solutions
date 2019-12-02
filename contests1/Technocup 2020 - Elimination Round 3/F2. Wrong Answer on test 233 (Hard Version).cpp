#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <array>
//#pragma GCC optimize("Ofast")
 
 
using namespace std;
using ll = long long;
 
const ll mod = 998244353;
const int maxn = 1000000;
ll fact[maxn];
 
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return a * pw(a, b - 1) % mod;
    ll c = pw(a, b / 2);
    return c * c % mod;
}
 
ll divide(ll a, ll b) {
    return pw(b, mod - 2) * a % mod;
}
 
ll calc_c(ll n, ll k) {
    return divide(fact[n], fact[k] * fact[n - k] % mod);
}
 
ll calc_f(ll n) {
    if (n % 2 == 1) {
        return pw(2, n - 1);
    }
    return divide((pw(2, n) - calc_c(n, n / 2) + mod) % mod, 2);
}
 
int main()
{
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto b = a;
    b.push_back(b[0]);
    b.erase(b.begin());
    ll ans = 0;
    ll d = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) d *= k, d %= mod;
        else cnt++;
    }
    for (int cnt2 = 0; cnt2 <= cnt; cnt2++) {
        ll cur = pw(k - 2, cnt2);
        //cout << cnt - cnt2 << ' ' << calc_f(cnt - cnt2) << endl;
        cur *= calc_f(cnt - cnt2);
        cur %= mod;
        cur *= calc_c(cnt, cnt2);
        //cout << cur << endl;
        ans += cur, ans %= mod;
    }
    ans = (ans * d) % mod;
    cout << ans << endl;
    return 0;
}
