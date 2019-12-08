#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double a,b,f,e=10000000,k;
	cin>>n>>a>>b;
	double p[n];
	for(int i=0;i<n;i++)
	cin>>p[i];
	double c,d;
	cin>>c>>d;
	for(int i=0;i<n;i++)
	{
	f=p[i]/a+sqrt((c-p[i])*(c-p[i])+d*d)/b;
	if(f<=e&&i!=0)
	{
		e=f;
		k=i;
	
	}
	}
	cout<<k+1;
}
