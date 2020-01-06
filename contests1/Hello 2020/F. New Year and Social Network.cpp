#include<bits/stdc++.h>
using namespace std;
 
const int maxn=250005;
int n,m;
vector<pair<int,int> >edge[maxn],ans;
int a[maxn],b[maxn],u[maxn],v[maxn];
 
namespace Lct{
	const int maxm=maxn*3;
	int top;
	int f[maxm],ch[maxm][2],st[maxm];
	bool rev[maxm],cur[maxm],alive[maxm];
	bool isroot(int x){
		return ch[f[x]][0]!=x&&ch[f[x]][1]!=x;
	}
	void apply(int x){
		swap(ch[x][0],ch[x][1]);
		rev[x]^=1;
	}
	void pushdown(int x){
		if(rev[x]){
			if(ch[x][0])apply(ch[x][0]);
			if(ch[x][1])apply(ch[x][1]);
			rev[x]=0;
		}
	}
	void print(int x){
		pushdown(x);
		if(ch[x][0])print(ch[x][0]);
		printf("%d(%d) ",x,alive[x]);
		if(ch[x][1])print(ch[x][1]);
	}
	void update(int x){
		alive[x]=cur[x];
		if(ch[x][0])alive[x]|=alive[ch[x][0]];
		if(ch[x][1])alive[x]|=alive[ch[x][1]]; 
	}
	void rotate(int x){
		int y=f[x],z=f[y],d=ch[y][1]==x;
		if(!isroot(y))ch[z][ch[z][1]==y]=x;
		f[x]=z;f[y]=x;f[ch[x][!d]]=y;
		ch[y][d]=ch[x][!d];ch[x][!d]=y;
		update(y);update(x);
	}
	void splay(int x){
		int top=0;st[++top]=x;
		for(int i=x;!isroot(i);i=f[i])st[++top]=f[i];
		while(top)pushdown(st[top--]);
		for(int y=f[x],z=f[y];!isroot(x);y=f[x],z=f[y]){
			if(!isroot(y))((ch[z][1]==y)^(ch[y][1]==x))?rotate(x):rotate(y);
			rotate(x);
		}
	}
	void access(int x){
		int y=0;
		while(x){
			splay(x);
			ch[x][1]=y;
			update(x);
			y=x;x=f[x];
		}
	}
	void makeroot(int x){
		access(x);
		splay(x);
		apply(x);
	}
	void link(int x,int y){
		makeroot(x);
		f[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);
		access(y);
		splay(x);
		ch[x][1]=f[y]=0;
		update(x);
	}
	void assign(int x,bool _cur){
		access(x);
		splay(x);
		cur[x]=_cur;
		update(x);
	}
	int go(int x){
		pushdown(x);
		if(ch[x][0]&&alive[ch[x][0]])return go(ch[x][0]);
		else if(cur[x])return x;
		else return go(ch[x][1]);
	}
	int query(int x,int y){
		makeroot(x);
		access(y);
		splay(x);
		return go(x);
	}
}
 
void dfs(int x,int p,int pe){
	for(int i=0;i<int(edge[x].size());i++){
		pair<int,int>y=edge[x][i];
		if(y.first==p)continue;
		dfs(y.first,x,y.second);
	}
	if(p>0){
		int e=Lct::query(x,p)-n;
		ans.push_back(make_pair(pe,e));
		Lct::cut(u[e],e+n);
		Lct::cut(v[e],e+n);
		m++;
		Lct::link(x,m+n);
		Lct::link(p,m+n);
	}
}
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&a[i],&b[i]);
		edge[a[i]].push_back(make_pair(b[i],i));
		edge[b[i]].push_back(make_pair(a[i],i));
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u[i],&v[i]);
		Lct::link(u[i],i+n);
		Lct::link(v[i],i+n);
		Lct::assign(i+n,true);
	}
	m=n-1;
	dfs(1,0,0);
	printf("%d\n",int(ans.size()));
	for(int i=0;i<int(ans.size());i++)
		printf("%d %d %d %d\n",a[ans[i].first],b[ans[i].first],u[ans[i].second],v[ans[i].second]);
	return 0;
}
