#include <iostream>
#include <vector>
 
#define int long long
 
using namespace std;
 
const int MOD = 998244353;
 
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
 
    vector<int> pw(n + 1);
    vector<int> pw2(n + 1);
    pw[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= n; i++){
        pw[i] = (pw[i - 1] * k) % MOD;
        pw2[i] = (pw2[i - 1] * (k - 2)) % MOD;
    }
 
    vector<vector<int> > c(n + 1, vector<int>(n + 1));
    c[0][0] = 1;
    for (int i = 1; i <= n; i++){
        c[i][0] = 1;
        for (int j = 1; j <= n; j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
 
    /*for (auto i : c){
        for (auto j : i){
            cout << j << ' ';
        }
        cout << "\n";
    }
    cout << "\n";*/
 
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (h[i] != h[(i + 1) % n]){
            cnt++;
        }
    }
    int r = pw[n - cnt];
    int ans = 0;
    for (int a = 1; a <= cnt; a++){
        for (int b = 0; b < a; b++){
            if (a + b > cnt){
                continue;
            }
            int cur = (c[cnt][a] * c[cnt - a][b]) % MOD;
            cur = (cur * pw2[cnt - a - b]) % MOD;
            ans = (ans + cur) % MOD;
        }
    }
    ans = (ans * r) % MOD;
    cout << ans << endl;
    return 0;
}
