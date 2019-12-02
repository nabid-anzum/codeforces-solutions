#include <bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define pb push_back
#define pf push_front
#define str to_string
#define upper(s) transform(s.begin(),s.end(),s.begin(),::toupper)
#define lower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define ll long long
vector<int> c,s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q,w,x,y,ans=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >>q>> w;
        c.pb(q);s.pb(w);
    }
    for (int i=0;i<n;i++) {
        ans=0;
        if (s[i]>c[i]) {
            x=s[i]/c[i];
            y=s[i]%c[i];
            ans+=(y*(x+1)*(x+1))+((c[i]-y)*x*x);
        }
        else {
            ans+=s[i];
        }
        cout << ans << endl;
    }
    return 0;
}
