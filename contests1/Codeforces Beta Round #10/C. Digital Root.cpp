#include<iostream>
int n,i,j;
__int64 t,a[9];
int main()
{
	std::cin>>n;
	for(i=1;i<=n;i++)a[i%9]++,t-=n/i;
	for(i=0;i<9;i++)for(j=0;j<9;j++)t+=a[i]*a[j]*a[i*j%9];
	std::cout<<t;
}
