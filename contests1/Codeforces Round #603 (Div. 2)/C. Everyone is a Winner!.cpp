#include<bits/stdc++.h>
using namespace std;
int T,n,cnt,ans[10000000];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cnt=0;
		for(int i=1;i<=n;i++)ans[++cnt]=n/i,i=n/(n/i);
		printf("%d\n0 ",cnt+1);for(int i=cnt;i>=1;i--)printf("%d ",ans[i]);printf("\n");
	}
}
