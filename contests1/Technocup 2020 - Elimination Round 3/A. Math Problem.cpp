#include<iostream>
 
using namespace::std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,maxn=0,minn=1e9;
		cin>>n;
		for(int i=0,l,r;i<n;i++)
			cin>>l>>r,maxn=max(l,maxn),minn=min(r,minn);
		cout<<max(0,maxn-minn)<<'\n';
 
	}
}
