#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    vector<pair<int,int> > vp;
    multiset<int> ma;
    int n,m,a[110000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        int sum=-1,j=1;
    for(int i=1;i<=n;i++){
        ma.insert(a[i]);
        while(*ma.rbegin()-*ma.begin()>m) ma.erase(ma.find(a[j++]));
        if(i-j+1>sum){
            sum=i-j+1;
            vp.clear();
        }
        if(i-j+1==sum){
            vp.push_back(make_pair(j,i));
        }
    }
    cout<<sum<<" "<<vp.size()<<endl;
    for(int i=0;i<vp.size();i++)
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
}
