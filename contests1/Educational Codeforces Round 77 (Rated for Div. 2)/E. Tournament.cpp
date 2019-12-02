#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[1<<18|3];
priority_queue<int>q;
int main(){
	int n;LL ans=0,remain,d=2;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	if(a[n-1]==-1)return puts("0"),0;
	ans+=a[n-1],remain=n/d;
	for(int i=n-2;i;i--){
		if(a[i]==-1)break;
		q.push(-a[i]);remain--;
		if(remain==0){
			d*=2;remain=n/d;
			ans-=q.top();q.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
