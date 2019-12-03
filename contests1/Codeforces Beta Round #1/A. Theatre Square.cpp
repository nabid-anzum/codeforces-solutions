#include<bits\stdc++.h>
using namespace std;
int main()
{
    long long n,m,a,sum1=0,sum2=0;
    cin>>n>>m>>a;
    sum1=n/a;
    if(n%a!=0)
        sum1+=1;
    sum2=m/a;
    if(m%a!=0)
        sum2+=1;
    cout<<sum1*sum2;
    return 0;
}
