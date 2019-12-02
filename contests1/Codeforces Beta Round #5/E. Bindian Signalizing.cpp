#include<bits/stdc++.h>
#define maxn 1000005
int a[maxn],l[maxn],r[maxn],c[maxn];
long long ans;
int main(){
	int n;scanf("%d",&n);for(int i=0;i<n;i++) scanf("%d",a+i);
	std::rotate(a,std::max_element(a,a+n),a+n);
	a[n]=a[0];
	for(int i=n-1;i>=0;i--){
		r[i]=i+1;
		while(r[i]<n&&a[r[i]]<=a[i])	{if(a[r[i]]==a[i]) c[i]=c[r[i]]+1;r[i]=r[r[i]];}
	}
	for(int i=0;i<=n-1;i++){
		ans+=c[i];
		if(a[i]==a[0])	continue;
		l[i]=i-1;
		while(l[i]>0&&a[l[i]]<=a[i])	l[i]=l[l[i]];
		ans+=2;
		if(l[i]==0&&r[i]==n)	ans--;
	}
	std::cout<<ans<<std::endl;
}
