
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
 
using namespace std;
 
const int N=60;
int n,a[N]; ll k,dp[N][2][2];
 
ll dfs(int p,int x,int y){
	if (p>n-p+1) return 1;
	if (~dp[p][x][y]) return dp[p][x][y];
	ll res=0;
	rep (i,0,1) if (a[p]!=(i^1))
		rep (j,0,1) if (a[n-p+1]!=(j^1)){
			if (x&&i>j||y&&i>!j||p==n-p+1&&i!=j) continue;
			res+=dfs(p+1,x&&i==j,y&&i!=j);
		}
	dp[p][x][y]=res;
	return res;
}
 
int main(){
	scanf("%d%lld",&n,&k); k++;
	memset(a,-1,sizeof(a)); memset(dp,-1,sizeof(dp));
	a[1]=0;
	if (dfs(1,1,1)<k) return puts("-1"),0;
	rep (i,2,n){
		a[i]=0;
		memset(dp,-1,sizeof(dp));
		ll tmp=dfs(1,1,1);
		if (tmp<k) k-=tmp,a[i]=1;
	}
	rep (i,1,n) putchar(a[i]+'0');
	return 0;
}
