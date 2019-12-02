#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],l[maxn],r[maxn],d[maxn];
int sum[maxn];
int m,n,k,t;
bool judge(int v)
{
	memset(sum,0,sizeof(sum));
	for(int i=0;i<k;i++)
		if(d[i]>v){
			sum[l[i]]++;sum[r[i]+1]--;
		}
	int res=1;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		res++;
		if(sum[i])	res+=2;
	}
	return res<=t;
}
int main()
{
	scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=1;i<=m;i++)	scanf("%d",&a[i]);
	for(int i=0;i<k;i++)
		scanf("%d%d%d",&l[i],&r[i],&d[i]);
	sort(a+1,a+1+m);
	int l1=0,r1=m;
	while(l1<r1){
		int mid=(l1+r1+1)>>1;
		//printf("%d %d\n",l1,r1);
		if(judge(a[m-mid+1])){
			l1=mid;
		}
		else
			r1=mid-1;
	}
	printf("%d\n",l1);
}
