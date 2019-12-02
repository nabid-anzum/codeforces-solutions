#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
map<int,int> mp;
int pre[N],n;
string a[N];
int fi(int x)
{
	if(x==pre[x])
	return x;
	else
	return fi(pre[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n+26;i++)
	{
		pre[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			pre[fi(i)]=pre[fi(n+a[i][j]-'a'+1)];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[fi(i)]==0)
		{
			ans++;
			mp[fi(i)]=1;
		}
	}
	printf("%d\n",ans);
}
