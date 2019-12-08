#include<iostream>
using namespace std;
int k;
int abs(long long n)
{
	if(k<n)return 0;
	else return 1+abs(n*10)+abs(n*10+1);
}
int main()
{
	cin>>k;
	cout<<abs(1);
}
