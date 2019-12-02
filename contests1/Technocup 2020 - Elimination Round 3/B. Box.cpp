#include<bits/stdc++.h>
using namespace std;
 
#define ran 101101
 
int n;
int a[ran];
int v[ran];
 
int main() {
	int T;
	for(scanf("%d", &T);T--;) {
		scanf("%d", &n);
		
		int it = 1;
		int h = 0;
		bool chk = true;
		for(int i=1;i<=n;i++) {
			int x;
			scanf("%d", &x);
			
			while(x>=it) v[h++] = it++;
			if(h>0) a[i] = v[--h];
			else chk = false;
		}
		if(!chk) puts("-1");
		else
			for(int i=1;i<=n;i++)
				printf("%d%c", a[i], i<n ? ' ' : '\n');
	}
	
	return 0;
}
