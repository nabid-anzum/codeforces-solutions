#include<bits/stdc++.h>
using namespace std;
char a[9];
int wo,wx;
int co,cx;
int judge(int i,char s)
{
	if(a[3*i]==s && a[3*i+1]==s && a[3*i+2]==s || a[i]==s && a[i+3]==s && a[i+6]==s || a[0]==s && a[4]==s && a[8]==s ||a[2]==s && a[4]==s && a[6]==s)
	return 1;
	else
	return 0;
}
int main()
{
	for(int i=0;i<9;i++)
	{
		cin>>a[i];
		if(a[i]=='0')
		co++;
		if(a[i]=='X')
		cx++;
	}
	for(int i=0;i<3;i++)
	{
		wo=max(judge(i,'0'),wo);
		wx=max(judge(i,'X'),wx);
	}
	if((wx && cx!=co+1) || (wo && cx!=co) || (cx!=co+1 && cx!=co) || wo && wx)
	cout<<"illegal";
	else if(wx)
	cout<<"the first player won";
	else if(wo)
	cout<<"the second player won";
	else if(cx+co==9)
	cout<<"draw";
	else if(cx==co)
	cout<<"first";
	else
	cout<<"second";
	return 0;
}
