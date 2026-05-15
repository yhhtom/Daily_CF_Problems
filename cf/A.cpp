#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
int mod=676767677;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    bool only1=true;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    while(!v.empty()&&v.back()==1){
        v.pop_back();
        ans=1;
    }
    n =v.size();
    for(int i=0;i<n;i++){
        if(v[i]!=1) ans+=v[i];
        ans%=mod;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}