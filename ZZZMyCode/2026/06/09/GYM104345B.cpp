#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
//维护s的并查集模板
const int N=3e5;
int p[N],s[N];
void reset(int n){
    for(int i=0;i<n;i++)	//初始化,假定节点编号是1~n
    {						//s[]只有祖宗节点的有意义,表示祖宗节点所在集合中的点的数量
        p[i]=i;
        s[i]=1;
    }
}
int find (int x)	//返回x的祖宗节点 + 路径压缩
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
bool lead(int x){
    return find(x)==x;
}
void merge(int a,int b){
    //合并a和b所在的两个集合
    s[find(b)]+=s[find(a)];
    p[find(a)]=find(b);
    //注意:顺序不能调换
}
void solve(){
    int n;
    cin>>n;
    reset(n);
    vector<vector<int>> g(n+5,vector<int>(0));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> parent(n+5,-1);
    auto dfs = [&](auto &self, int v,int u) -> void {
        parent[v]=u;
        for(int i:g[v]){
            if(i!=u){
                self(self, i, v);
            }
        }
    };
    dfs(dfs,0,-1);
    int q;
    cin>>q;
    vector<int> vis(n+5,0);
    for(int i=0;i<q;i++){
        // cout<<i<<": \n";
        int k;
        cin>>k;
        vector<int> node(k);
        for(int j=0;j<k;j++) cin>>node[j],node[j]--,vis[node[j]]=1;
        for(int x:node){
            // cout<<x<<' '<<parent[x]<<endl;
            if(x&&vis[parent[x]]){
                // cout<<x<<endl;
                merge(x,parent[x]);
            }
        }
        int ans=0;
        for(int x:node){
            if(lead(x)){
                // cout<<x<<endl;
                ans+=s[x]*(s[x]-1)/2;
            }
        }
        cout<<ans<<'\n';
        for(int x:node){
            p[x]=x;
            s[x]=1;
            vis[x]=0;
        }
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