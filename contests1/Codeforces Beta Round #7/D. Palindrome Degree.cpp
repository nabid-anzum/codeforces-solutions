#include <iostream>
#include <cstdio>
using namespace std;
char s[5000010];
int f[5000010];
int main(){
	scanf("%s", s);
	int l=0, r=0, e=1, ans=0;
	for (int i=0; s[i]; i++){
		l=l*41+s[i];
	 	r=r+s[i]*e; e*=41; 
		if (l==r)	f[i+1]=f[(i+1)/2]+1;
		ans+=f[i+1];
	}
	cout<<ans<<endl;
}
