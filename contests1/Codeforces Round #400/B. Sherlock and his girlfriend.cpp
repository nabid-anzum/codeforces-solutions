#include<bits/stdc++.h>
using namespace std;
bool prime(int n)
{
  bool isPrime=true;
  int i;
  for(i=2;i<=n/2;++i)
  {
      if(n%i==0)
      {
          isPrime=false;
          break;
      }
  }
  if(isPrime)
      return 1;
 
  return 0;
}
int main()
{
    int n,j=0;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    int arr[n+1];
    for(int i=2;i<=n+1;i++){
        bool t=prime(i);
        if(t==1)
            arr[i-2]=1;
        else
            arr[i-2]=2;
    }
    cout<<2<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
