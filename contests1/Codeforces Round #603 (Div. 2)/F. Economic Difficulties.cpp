#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,m[2],z;
vector<int>gph[2][maxn];
int mat[2][maxn],nxt[2][maxn][12],dep[2][maxn];
void dfs(int x,int p)
{
	nxt[z][x][0]=p;
	dep[z][x]=dep[z][p]+1;
	for(int i=1;nxt[z][x][i-1];i++)
		nxt[z][x][i]=nxt[z][nxt[z][x][i-1]][i-1];
	for(int &i:gph[z][x])
		dfs(i,x);
}
int lca(int z,int u,int v)
{
	if(dep[z][u]<dep[z][v])swap(u,v);
	int d=dep[z][u]-dep[z][v];
	for(int i=0;i<12;i++)
		if(d>>i&1)u=nxt[z][u][i];
	if(u==v)return u;
	for(int i=12;i--;)
		if(nxt[z][u][i]!=nxt[z][v][i])
			u=nxt[z][u][i],
			v=nxt[z][v][i];
	return nxt[z][u][0];
}
int dp[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(z=0;z<2;z++)
	{
		scanf("%d",m+z);
		for(int p,i=2;i<=m[z];++i)
			scanf("%d",&p),
			gph[z][p].push_back(i);
		dep[z][0]=-1;
		dfs(1,0);
		for(int i=1;i<=n;i++)
			scanf("%d",mat[z]+i);
 
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			int k=max(i,j)+1;
			dp[k][j]=min(dp[k][j],
				dp[i][j]+dep[0][mat[0][k]]-(i==0?0:dep[0][lca(0,mat[0][i],mat[0][k])]));
			dp[i][k]=min(dp[i][k],
				dp[i][j]+dep[1][mat[1][k]]-(j==0?0:dep[1][lca(1,mat[1][j],mat[1][k])]));	
		}
	int ans=1000000;
	for(int i=0;i<n;i++)
		ans=min({ans,dp[n][i],dp[i][n]});
	printf("%d\n",m[0]+m[1]-2-ans);
	return 0;
}
