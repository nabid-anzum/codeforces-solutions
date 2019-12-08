#include<bits/stdc++.h>
using namespace std;
int n,lim,x[25],y[25],f[16777216],g[16777216],d[25][25];
void out(int s){
	if(!s)return;
	for(int i=0;i<n;i++)if((s^g[s])>>i&1)printf("%d ",i+1);
	printf("0 "),out(g[s]);
}
int main(){
	scanf("%d%d%d",&x[0],&y[0],&n),memset(f,0x7f,sizeof(f)),f[0]=0,lim=1<<n;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=n;i++)for(int j=0,a,b;j<=n;j++)a=x[i]-x[j],b=y[i]-y[j],d[i][j]=a*a+b*b;
	for(int s=0,k,t;s<lim;s++){
		for(int i=0;i<n;i++)if(!(s>>i&1)){k=i+1,t=s|(1<<i);break;}
		for(int i=0;i<n;i++)if(!(s>>i&1)&&f[t|(1<<i)]>f[s]+d[0][i+1]+d[i+1][k]+d[k][0])
		f[t|(1<<i)]=f[s]+d[0][i+1]+d[i+1][k]+d[k][0],g[t|(1<<i)]=s;
	}
	printf("%d\n0 ",f[lim-1]),out(lim-1);
}
