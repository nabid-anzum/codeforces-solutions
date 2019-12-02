#include<bits/stdc++.h>
using namespace std;
 
#define ran 1011
 
int n;
pair<int, int> a[ran];
char ans[ran][ran];
 
int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a+n);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<n;j++) ans[i][j] = '0';
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<a[i].first;j++)
			ans[(n-1-i+j)%(n+1)][a[i].second] = '1';
		
	printf("%d\n", n+1);
	for(int i=0;i<=n;i++) {
		ans[i][n] = 0;
		printf("%s\n", ans[i]);
	}
	
	return 0;
}
