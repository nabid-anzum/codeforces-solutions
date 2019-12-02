#include<bits/stdc++.h>
using namespace std;
 
int n;
int a[111];
 
bool chk(int x, int id) {
	for(int i=0; i<n; i++)
		if(i!=id && x==a[i]) return false;
	return true;
}
 
int main() {
	int T;
	for(scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%d", &a[i]);
		
		int ans = 0;
		for(int i=0;i<n;i++)
			if (!chk(a[i], i)) {
				ans++;
				a[i] %= 1000;
				while(!chk(a[i], i)) a[i]+=1000;
			}
			
		printf("%d\n", ans);
		for(int i=0;i<n;i++) printf("%04d\n", a[i]);
	}
	
	return 0;
}
