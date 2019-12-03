#include<bits/stdc++.h>
 
using namespace std;
 
int a[4],b;
int main()
{
	for(int i = 0;i<4; ++i)cin>>a[i];
	sort(a,a+4);
	b= max(a[0]+a[1]-a[2],a[1]+a[2]-a[3]);
	puts(b>0?"TRIANGLE":b?"IMPOSSIBLE":"SEGMENT");
    
    return 0;
}
