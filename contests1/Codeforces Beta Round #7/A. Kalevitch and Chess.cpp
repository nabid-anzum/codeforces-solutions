#include <bits/stdc++.h>
using namespace std;
char s[8];
int a,b,c;
int main(){
	for(int i=0;i<8;i++){
		c=0;
		for(int j=0;j<8;j++){
			cin>>s[j];
			if(s[j]=='B')c++;
		}
		if(c==8)a++;
		else b=c;
	}
	cout<<a+b<<endl;
}
