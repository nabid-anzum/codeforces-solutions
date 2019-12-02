#include <bits/stdc++.h>
using namespace std;
int main() {
	string x;
	vector<string> s;
	int mx = 0;
	while (getline(cin, x))
		s.push_back(x),
		mx=max(mx,(int)x.size());
	cout<<string(mx+2,'*')<<endl;
	int c=1,ss;
	for (int i=0; i<(int)s.size(); i++)
		ss=(mx-(int)s[i].size()),
		c+=(ss&1),
		cout<<"*"<<string(ss/2+(ss&1)*(c&1),' ')<<s[i]<<string(ss-ss/2-(ss&1)*(c&1),' ')<<"*"<<endl;
	cout<<string(mx+2,'*')<<endl;
	return 0;
}
