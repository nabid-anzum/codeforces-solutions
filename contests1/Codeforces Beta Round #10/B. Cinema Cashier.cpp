#include <cstdio>
#include <cmath>
int n,k,i,j,x,y,s,p,l,f,t,t1,t2,a[110][110];
bool ok;
int main() 
{
	scanf("%d%d",&n,&k);
	x=y=(k+1)/2;
	for (i=1;i<=n;i++) 
	{
		scanf("%d",&t);
		f=-1;
		for (j=1;j<=k;j++)
			for (l=1;l+t-1<=k;l++) 
			{
				s=0;ok=true;
				for (p=l;p<l+t;p++) 
				{
					if (a[j][p]==1) 
					{
						ok=false;
						break;
					}
					s+=fabs(j-x)+fabs(p-y);
				}
				if (ok&&((f<0)||(s<f))) 
				{
					t1=j;t2=l;f=s;
				}
			}
		if (f<0) printf("-1\n");
		else 
		{
			printf("%d %d %d\n",t1,t2,t2+t-1);
			for (j=t2;j<=t2+t-1;j++) a[t1][j]=1;
		}
	}
	return 0;
}
