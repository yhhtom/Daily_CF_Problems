#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
signed main(){
    int n;
    cin>>n;
    vector<array<int,3>> pts(n+5);
    vector<vector<PII>> e(n+5);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        e[u].pb(mp(v,w));
        e[v].pb(mp(u,w));
    }
    for(int i=0;i<n;i++){
        cin>>pts[i][0]>>pts[i][1]>>pts[i][2];
    }
    int total_ans=0;
    auto dfs = [&](auto &self, int u, int f) -> array<int,8> {
        array<int,8> ans;
        for(int i=0;i<8;i++){
            ans[i]=0;
            for(int j=0;j<3;j++){
                if(i>>j&1){
                    ans[i]+=pts[u][j];
                }else{
                    ans[i]-=pts[u][j];
                }
            }
        }
        for(auto [v,w]:e[u]){
            if(v!=f){
                auto res=self(self,v,u);
                for(int i=0;i<8;i++){
                    total_ans=max(total_ans,ans[i]+res[7^i]+w);
                }
                for(int i=0;i<8;i++){
                    ans[i]=max(ans[i],res[i]+w);
                }
            }
        }
        return ans;
    };
    dfs(dfs,0,-1);
    cout<<total_ans<<'\n';
    return 0;
}