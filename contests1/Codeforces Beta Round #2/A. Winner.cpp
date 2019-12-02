#include <bits/stdc++.h>
using namespace std;
#define r(i,a,n) for(int (i)=a;i<n;i++)
#define vii vector<int,int>
#define ll long long int
#define it iterator
#define lr(i,a,n) for(long long int (i)=a;i<n;i++)
//@return returns array of primenumbers
vector<int> sieve(){
    vector<int> prime;
    bool a[1000001];
    memset(a,1,1000001);
    a[0]=a[1]=0;
    lr(i,2,1000001)
    {
        if(a[i])
        {for(long long int j=i*i;j<1000001;j+=i)
        {
            a[j]=0;
        }}
    }
    r(i,2,1000001)
    {
        if(a[i])
        {
            prime.push_back(i);
        }
    }
    return prime;
}
//@returns array of numbers with smallest prime factor
vector<int> spfsieve()
{
 vector<int> spf(1000001);
 spf[0]=spf[1] = 1;
 for (int i=2; i<1000001; i++)
 {spf[i] = i;}
 for (int i=4; i<1000001; i+=2)
 {spf[i] = 2;}
 
 for (long long int i=3; i*i<1000001; i++)
 {
 if (spf[i] == i)
 {
 for (long long int j=i*i; j<1000001; j+=i)
 if (spf[j]==j)
 spf[j] = i;
 }
 }
 return spf;
}
//@param x=number to be factorized@param spf array of smallest prime factors @return vector of prime factors
vector<int> getPrimeFactorization(int x,vector<int> spf)
{
 vector<int> fact;
 int y=1;
 while (x != 1)
 {
 if(y!=spf[x])
 {
 fact.push_back(spf[x]);
 }
 y=spf[x];
 x = x / spf[x];
 }
 return fact;
}
 //@param x=number to be factorized@param spf array of smallest prime factors @return vector of power of prime factors
vector<int> getPrimePower(int x,vector<int> spf)
{
 vector<int> power;
 int y=1;
 int k=0;
 power.push_back(1);
 while (x != 1)
 {
 if(y!=spf[x])
 {
 power.push_back(1);
 k++;
 }
 if(y==spf[x])
 power[k]+=1;
 
 y=spf[x];
 x = x / spf[x];
 }
 power.erase(power.begin());
 return power;
}
vector<int> divisor;
//@param currentDivisor 0 @param currentResult 1
void findFactors(vector<int> primeDivisors, vector<int> primePower, long currentDivisor, long currentResult) {
    if (currentDivisor == primeDivisors.size()) {
        divisor.push_back(currentResult);
        return;
    }
    for (int i = 0; i <= primePower[currentDivisor]; ++i) {
        findFactors(primeDivisors, primePower, currentDivisor + 1, currentResult);
        currentResult *= primeDivisors[currentDivisor];
    }
}
long long int expo(long long int a,long long int n)
{
    if(n==1)
    {
        return a;
    }
    if(n%2==0)
    {
        long long int temp=expo(a,n/2);
        return temp*temp;
    }
    else
    {
        long long int temp=expo(a,n/2);
        return temp*temp*a;
    }
    
}
long long int modexpo(long long int a,long long int n,long long int m)
{
    if(n==1)
    {
        return a%m;
    }
    if(n%2==0)
    {
        long long int temp=modexpo(a,n/2,m);
        return ((temp%m)*(temp%m))%m;
    }
    else
    {
        long long int temp=modexpo(a,n/2,m);
        return ((temp%m)*(temp%m)*(a%m))%m;
    }
    
}
long long int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int n;
    cin>>n;
    int ans;
    string name;
    map<string,int> a;
    vector<pair<string,int>> b;
    r(i,0,n)
    {
        string s;
        int m;
        cin>>s>>m;
       // cout<<s<<m;
        b.push_back(make_pair(s,m));
        map<string,int>::iterator it=a.find(s);
        if(it==a.end())
        {
            a.insert(make_pair(s,m));
        }
        else
        {
            it->second+=m;
    }
    }
    map<string,int>::iterator it1;
    for(it1=a.begin();it1!=a.end();it1++)
    {
        if(it1==a.begin())
        {
            ans=it1->second;
        }
        else
        {
            if(it1->second>ans)
            {
                ans=it1->second;
            }
          }
    }
  //  cout<<ans;
    map<string,int> c;
    r(i,0,n)
    {
        string s=b[i].first;
        int m=b[i].second;
        //cout<<b[i].first;
        map<string,int>::iterator it=c.find(s);
        if(it==c.end())
        {
            c.insert(make_pair(s,m));
            map<string,int>::iterator it1=a.find(s);
            if(m>=ans&&it1->second==ans)
            {
            name=s;
            break;
            }
        }
        else
        {
            it->second+=m;
            map<string,int>::iterator it1=a.find(s);
             if((it->second)>=ans&&it1->second==ans)
             {
                 name=it->first;
                 break;
             }
        }
    }
    cout<<name;
    return 0;
}
