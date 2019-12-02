#include <bits/stdc++.h>
#define f(i,j) for(int i=0; i<j; i++)
#define p(a) ((a)*(a))
int f;
double s,dx,dy,x[3],y[3],r[3],t[3];
double F(double dx, double dy) {
 double ret=0;
 f(i,3) t[i]=sqrt(p(dx-x[i])+p(dy-y[i]))/r[i];
 f(i,3) ret+=p(t[i]-t[(i+1)%3]);
 return ret;
 using namespace std;
}
int main(){
 f(i,3) scanf("%lf%lf%lf",x+i,y+i,r+i);
 f(i,3) dx+=x[i]/3, dy+=y[i]/3;
 for (s=1; s>1e-6; ) {
  if (F(dx,dy)>F(dx+s,dy)) dx+=s;
  else if (F(dx,dy)>F(dx-s,dy)) dx-=s;
  else if (F(dx,dy)>F(dx,dy+s)) dy+=s;
  else if (F(dx,dy)>F(dx,dy-s)) dy-=s;
  else s*=0.7;
 }
 if (F(dx,dy)<1e-5) printf("%.5lf %.5lf\n",dx,dy);
 return 0;
}
