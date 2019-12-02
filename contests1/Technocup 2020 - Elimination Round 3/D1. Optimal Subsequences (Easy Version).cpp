#include<bits/stdc++.h>
using namespace std;
int a[101];
bool vis[101];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int k,pos;
		scanf("%d %d",&k,&pos);
		memset(vis,false,sizeof(vis));
		while(k--)
		{
			int p=0;
			for(int i=1;i<=n;i++)
				if(!vis[i]&&a[i]>a[p])
					p=i;
			vis[p]=true;
		}
		int ans=0;
		while(pos--)
			while(!vis[++ans]);
		printf("%d\n",a[ans]);
	}
	return 0;
}
