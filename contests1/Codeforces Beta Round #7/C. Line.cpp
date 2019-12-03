#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int exgcd(ll a,ll b,ll &x,ll &y)
{
	ll d = a;
	if(b!=0)
	{
		d = exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else {x = 1 ;y = 0;}
	return d; 
}
int main()
{
	ll A,B,C,x,y;
	while(cin>>A>>B>>C)
	{
		ll d = exgcd(A,B,x,y);
		if(C%d!= 0) printf("-1\n");
		else printf("%lld %lld\n",-x*(C/d),-y*(C/d));
	}
	 return 0;
} 
