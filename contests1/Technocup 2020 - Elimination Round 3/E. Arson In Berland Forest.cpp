#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'X') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    int x[] = {1, -1, -1, 1, 0, 1, 0, -1};
    int y[] = {-1, 1, - 1, 1, 1, 0, -1, 0};
    int pref[n + 1][m + 1];
    for (int k = 0; k < n + 1; ++k) {
        pref[k][0] = 0;
    }
    for (int l = 0; l < m + 1; ++l) {
        pref[0][l] = 0;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            pref[i][j] = a[i - 1][j - 1] + pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
        }
    }
    int l = 0;
    int r = min(n, m) + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        int d = mid * 2 + 1;
        int t[n][m];
        int dist[n][m];
        bool used[n][m];
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < m; ++i) {
                t[k][i] = 0;
                dist[k][i] = 1e9;
                used[k][i] = false;
            }
        }
        for (int i = 0; i <= n - d; ++i) {
            for (int j = 0; j <= m - d; ++j) {
                int sum = pref[i + d][j + d] - pref[i + d][j] - pref[i][j + d] + pref[i][j];
                if (sum == d * d) {
                    t[i + mid][j + mid] = 1;
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i][j] == 1) {
                    q.push({i, j});
                    used[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
        while (q.size() != 0) {
            int xx = (q.front()).first;
            int yy = q.front().second;
            q.pop();
            for (int i = 0; i < 8; ++i) {
                int xxx = xx + x[i];
                int yyy = yy + y[i];
                if (xxx >= 0 && xxx < n && yyy >= 0 && yyy  < m && !used[xxx][yyy]) {
                    dist[xxx][yyy] = dist[xx][yy] + 1;
                    used[xxx][yyy] = true;
                    q.push({xxx, yyy});
                }
            }
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    if (dist[i][j] > mid) {
                        good = false;
                    }
                }
            }
        }
        if (good)l = mid;
        else r = mid;
    }
    cout << l << "\n";
    int mid = l;
    int d = mid * 2 + 1;
    int t[n][m];
    int used[n][m];
    int add[n][m];
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            t[k][i] = 0;
            used[k][i] = 0;
        }
    }
    for (int i = 0; i <= n - d; ++i) {
        for (int j = 0; j <= m - d; ++j) {
            int sum = pref[i + d][j + d] - pref[i + d][j] - pref[i][j + d] + pref[i][j];
            if (sum == d * d) {
                used[i][j] += 1;
                used[i + d - 1][j + d - 1] -= 1;
                add[i + d - 1][j + d - 1] += 1;
                t[i + mid][j + mid] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j] == 1) {
                cout << "X";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}
