#include<bits/stdc++.h>
using namespace std;
 
#define ran 2022
 
int n, k;
char s[ran], todo[ran];
pair<int, int> ans[ran];
 
int main() {
	int T;
	for(scanf("%d", &T); T--;) {
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		for(int i=0;i<k-1;i++) {
			todo[i*2] = '(';
			todo[i*2+1] = ')';
		}
		int rem = (n-(k-1)*2) / 2;
		for(int i=0;i<rem;i++)
			todo[(k-1)*2+i] = '(';
		for(int i=1;i<=rem;i++)
			todo[n-i] = ')';
		//for(int i=0;i<n;i++) putchar(todo[i]);
		//puts("");
		
		int la = 0;
		for(int i=0;i<n;i++)
			if(s[i] != todo[i]) {
				for(int j=i+1;j<n;j++)
					if(s[j]==todo[i]) {
						ans[la++] = make_pair(i+1, j+1);
						for(int l = i, r = j; l<r; l++, r--)
							swap(s[l], s[r]);
						break;
					}
			}
		
		printf("%d\n", la);
		for(int i=0;i<la;i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}
