#include <bits/stdc++.h>
using namespace std;
int n,m,b[256],S,i,j;
char q,a[150][150];
 
int main(){
	cin>>n>>m>>q;
 
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
 
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==q)
				b[ a[i-1][j] ] = b[a[i+1][j]] = b[a[i][j-1]] = b[a[i][j+1]] = 1;
 
	for(i='A';i<='Z';i++)
		S+=b[i];
 
	cout<<S-b[q];
}
