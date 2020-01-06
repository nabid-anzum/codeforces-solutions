#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[5005],b[5005],f[5005],g[5005];
void sc(int x)
{
	if(!x)return;
	sc(g[x]);
	printf("%d ",b[x]);
}
int main()
{
	int i,j,k=0,x=0,y;
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	cin>>m;
	for(i=1;i<=m;i++)scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])f[j]=f[k]+1,g[j]=k;
			if(a[i]>b[j]&&f[k]<f[j])k=j;
		}
		k=0;
	}
	for(i=1;i<=m;i++)
		if(f[i]>f[x])x=i;
	cout<<f[x]<<endl;
	sc(x);
}
