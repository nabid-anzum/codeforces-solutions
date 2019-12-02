#include<bits/stdc++.h>
using namespace std;
int main(){
	int p=0,sum=0;
	string s;
	while(getline(cin,s)){
	    if(s[0]=='+')p++;
		else if(s[0]=='-')p--;
		else sum+=p*(s.size()-s.find(':')-1);
	}
	cout<<sum;
}
