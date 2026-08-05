#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=(1ll<<n)-1ll;
    vector<int> v(n),a(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int p=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            a[i]=(1ll<<p);
            ans-=(1ll<<p);
            p++;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            a[i]=v[i]*(1ll<<p);
            p++;
        }
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
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