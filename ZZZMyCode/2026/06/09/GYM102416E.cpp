#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
struct node{
    int x,y,z,r,idx;
};
bool joint(node &t,node &o){
    int d2=(t.x-o.x)*(t.x-o.x)+(t.y-o.y)*(t.y-o.y)+(t.z-o.z)*(t.z-o.z);
    return (t.r+o.r)*(t.r+o.r)<d2;
}
void solve(){
    int n;
    cin>>n;
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].z>>v[i].r;
        v[i].idx=i;
    }
    sort(all(v),[&](node &t,node &o){return t.r>o.r;});
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<ans.size();j++){
            if(!joint(v[i],v[ans[j]])){
                ok=false;
            }
        }
        if(ok){
            ans.push_back(i);
        }
    }
    if(ans.size()==0){
        cout<<"NO\n";
    }else{
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++) cout<<v[ans[i]].idx+1<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}