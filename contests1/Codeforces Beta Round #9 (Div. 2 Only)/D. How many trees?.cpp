#include<cstdio>
 
int n,h;
long long f[36][36];
 
int main(void){
	register int i,j,k;
	scanf("%d%d",&n,&h);
	for(i=0;i<=n;++i)
		f[0][i]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=0;k<j;++k)
				f[j][i]+=f[k][i-1]*f[j-k-1][i-1];
	printf("%lld\n",f[n][n]-f[n][h-1]);
	return 0;
}
