#include<iostream>
#include<queue>
using namespace std;
priority_queue<int>q;
long long n,x,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
		if(q.top()>x){
			ans+=q.top()-x;
			q.pop();
			q.push(x);
		}
	}
	cout<<ans;
}
