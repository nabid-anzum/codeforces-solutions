#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,y,w,k;
    cin>>y>>w;
    if(y>w)
        l=y;
    else
        l=w;
    k=(6-l)+1;
    if(k==4)
        cout<<"2/3";
    if(k==5)
        cout<<"5/6";
    if(k!=4){
        if(6%k==0)
            cout<<1<<"/"<<6/k;
    }
    return 0;
}
