#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    map<string, int>p;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(p.find(s) == p.end()) {
			cout << "OK\n";
			p[s] = 1;
		}
		else {
			int k = ++p[s];
			cout <<s<<k-1 <<"\n";
		}
    }
    return 0;
}
