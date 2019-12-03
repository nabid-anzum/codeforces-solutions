#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	map<string,int>a;
	cin>>n;
	for(int i=n; i>=0; --i) {
		string s,p;
		if(i)scanf(" #%*s"),cin>>s;
		int &x=a[s],r,b=0,d=0;
		getline(cin,s);
		for(char c:s+".") {
			b+=c=='(';
			b-=c==')';
			if(!b)x|=(c=='+'||c=='-')*2+(c=='*'||c=='/');
			if(isalpha(c)||c==' '||isdigit(c)) {
				if(isalpha(c))p+=c;
				continue;
			}
			if(p!="") {
				r=a[p];
				if(r>1&&(d=='*'||d=='-'||c=='/'||c=='*')||
				        r &&d=='/'||r>3)x=4;
				p="";
			}
			d=c;
		}
	}
	puts(a[""]>3?"Suspicious":"OK");
}
