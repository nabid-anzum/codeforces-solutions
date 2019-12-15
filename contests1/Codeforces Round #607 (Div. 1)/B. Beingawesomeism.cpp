#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
 
int const N = 60, inf = 1e9;
char g[N][N + 1];
int n, m;
 
void solve(){
	scanf("%d%d", &n, &m);
	f(i, 0, n)scanf("%s", g[i]);
	int an = inf;
	f(i, 0, n)f(j, 0, m)if (g[i][j] == 'A'){
		int z = 2;
		if (i > 0 && i + 1 < n)++z;
		if (j > 0 && j + 1 < m)++z;
		an = min(an, z);
	}
	
	f(i, 0, n){
		int z = 0;
		f(j, 0, m)z += g[i][j] == 'A';
		if (z == m)an = min(an, 1 + (i > 0 && i + 1 < n));
	}
	
	f(j, 0, m){
		int z = 0;
		f(i, 0, n)z += g[i][j] == 'A';
		if (z == n)an = min(an, 1 + (j > 0 && j + 1 < m));
	}
	
	int z = 0;
	f(i, 0, n)f(j, 0, m)z += g[i][j] == 'A';
	if (z == n * m)an = 0;
	
	if (an == inf)printf("MORTAL\n");
	else printf("%d\n", an);
}
 
int main(){
	int t;
	scanf("%d", &t);
	while (t--)solve();
}
