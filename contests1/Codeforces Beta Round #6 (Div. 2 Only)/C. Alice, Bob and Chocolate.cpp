# include <cstdio>
 
int r,a,n,i,z[100001];
 
int main(){
 
    scanf("%d", &n);
 
    while ( i < n ) scanf("%d", &z[i++]);
 
    while ( i > a ) r > 0 ? r-=z[--i]:r+=z[a++];
 
    printf("%d %d", a, n-a);
}
