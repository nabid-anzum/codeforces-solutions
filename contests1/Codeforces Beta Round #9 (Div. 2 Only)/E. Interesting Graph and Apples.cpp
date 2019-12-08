#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,x,y,aim,fa[N],deg[N];
vector< pair<int,int> > ans;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		fa[find(x)]=find(y);
		++deg[x]; ++deg[y];
		if (deg[x]>2||deg[y]>2) return puts("NO"),0;
	}
	for (int i=2;i<=n;++i)
	for (int j=1;j<i;++j)
	if (deg[i]<=1&&deg[j]<=1&&find(i)!=find(j))
	{
		ans.push_back(make_pair(j,i));
		fa[find(i)]=find(j);
		++deg[i]; ++deg[j];
	}
	for (int i=2;i<=n;++i)
	{
		if (deg[i]==2) continue;
		for (int j=1;j<i;++j)
		if (deg[j]<=1)
		{
			ans.push_back(make_pair(j,i));
			fa[find(i)]=find(j);
			++deg[i]; ++deg[j];
		}
	}
	for (int i=1;i<=n;++i)
	if (!deg[i]) ans.push_back(make_pair(i,i));
	aim=find(1);
	for (int i=1;i<=n;++i)
	if (find(i)!=aim) return puts("NO"),0;
	printf("YES\n%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();++i)
	printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
