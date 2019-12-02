#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,ans=0;
string s;
struct tree
{
	int mxS,miS,sum;
};
tree nod[4*N];
void update(int id,int l,int r,int pos,int val)
{
	if (r < pos) return;
	if (l==r)
	{
		nod[id].mxS=val;
		nod[id].miS=val;
		nod[id].sum=val;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid)	update(id*2,l,mid,pos,val);
	else update(id*2+1,mid+1,r,pos,val);
	nod[id].mxS=max(nod[id*2].mxS,nod[id*2+1].mxS+nod[id*2].sum);
	nod[id].miS=min(nod[id*2].miS,nod[id*2+1].miS+nod[id*2].sum);
	nod[id].sum=nod[id*2].sum+nod[id*2+1].sum;
}
void process()
{
	if (nod[1].sum==0&&nod[1].miS==0)
		cout<<nod[1].mxS<<" ";
	else cout<<-1<<" ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>s;
	int cur=1;
	//update(1,1,n,cur,1);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='(')
		{
			update(1,1,n,cur,1);
			process();
			continue;
		}
		if (s[i]==')')
		{
			update(1,1,n,cur,-1);
			process();
			continue;
		}
		if (s[i]!='R'&&s[i]!='L')
		{
			update(1,1,n,cur,0);
			process();
			continue;
		}
		if (s[i]=='R') cur++,process();
		else cur=max(1,cur-1),process();
	}
	return 0;
}
