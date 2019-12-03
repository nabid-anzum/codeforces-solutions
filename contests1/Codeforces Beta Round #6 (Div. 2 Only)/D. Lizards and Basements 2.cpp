#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int n, a, b;
int h[maxn];
int ans = 1e9;
vector<int>G1, G2;
void dfs(int now, int step){
    if(step >= ans) return;
    if(now == n){
        if(h[now] < 0){
            G2 = G1;
            ans = step;
        }
        return;
    }
 
    for(int i = 0;i<=max(h[now-1]/b+1, max(h[now]/a+1, h[now+1]/b+1));i++){
        if(h[now-1] < b*i){
            h[now-1] -= b*i;
            h[now] -= a*i;
            h[now+1] -= b*i;
            for(int j = 0;j<i;j++)  G1.push_back(now);
            dfs(now+1, step+i);
            for(int j = 0;j<i;j++)  G1.pop_back();
            h[now-1] += b*i;
            h[now] += a*i;
            h[now+1] += b*i;
        }
    }
}
 
int main(){
    cin>>n>>a>>b;
    for(int i = 1;i<=n;i++) cin>>h[i];
    dfs(2, 0);
    cout<<ans<<endl;
    for(int i = 0;i<(int)G2.size();i++) cout<<G2[i]<<" ";
    return 0;
}
