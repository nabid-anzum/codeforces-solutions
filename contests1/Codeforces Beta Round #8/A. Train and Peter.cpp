
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int temp=0;
	string s,a,b,kq[4]={"fantasy","forward","backward","both"};
	cin>>s>>a>>b;
	if(s.find(a)!=-1 && s.find(b,a.size()+s.find(a))!=-1)
		temp++;
	reverse(s.begin(),s.end());
	if(s.find(a)!=-1 && s.find(b,a.size()+s.find(a))!=-1)
		temp+=2;
	cout<<kq[temp];
}
