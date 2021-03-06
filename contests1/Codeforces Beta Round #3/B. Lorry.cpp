#include <cstdio>
#include <algorithm>
 
#define REP(i,n) for(int i=0; i<(n); ++i)
 
const int n_max = 100100;
 
struct Boat { Boat(){} Boat(int _i, int _p, int _i2 = -1) : i(_i), p(_p), i2(_i2) {} int i,p,i2; };
 
bool cmp(Boat a, Boat b){ return a.p<b.p; }
 
Boat C[n_max]; int cs;
Boat K[n_max]; int ks;
bool G[n_max];
 
int main()
{
	int n,v; scanf("%d%d",&n,&v);
	REP(i,n)
	{
		int t,p; scanf("%d%d",&t,&p);
		if(t==1) K[ks++] = Boat(i,p); else C[cs++] = Boat(i,p);
	}
 
	std::sort(K,K+ks,cmp);
 
	int res=0;
	if(v&1 && ks){ res += K[--ks].p; G[K[ks].i] = 1; v--; }
	while(ks>1){ C[cs++] = Boat(K[ks-1].i,K[ks-1].p+K[ks-2].p,K[ks-2].i); ks-=2; }
	
	std::sort(C,C+cs,cmp);
	
	while(cs)
	{
		if(v<2) break;
		res += C[--cs].p; G[C[cs].i] = 1;
		if(C[cs].i2!=-1) G[C[cs].i2] = 1;
		v-=2;
	}
	if(v && ks){ res += K[0].p; G[K[0].i] = 1; v--; }
	
	printf("%d\n",res);
	REP(i,n) if(G[i]) printf("%d ",i+1); printf("\n");
	
	return 0;
}
