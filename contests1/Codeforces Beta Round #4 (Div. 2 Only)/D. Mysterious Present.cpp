#include<cstdio>
int n,w[5001],h[5001],to[5001],d[5001];
int dp(int v)
{
    if(d[v])return d[v];
    d[v]=1;
    for(int i=0;i<=n;i++)if(w[i]>w[v]&&h[i]>h[v])if(dp(i)+1>d[v])to[v]=i,d[v]=d[i]+1;
    return d[v];
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<=n;i++)to[i]=-1,scanf("%d%d",w+i,h+i);
    dp(0);
    printf("%d\n",--d[0]);
    for(i=to[0];i!=-1;i=to[i])printf("%d ",i);
}
