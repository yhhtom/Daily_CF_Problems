#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n,L;
    cin>>n>>L;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));
    for(int i=0;i<n;i++) v.push_back(v[i]+L);
    int l=0,r=0;
    int ans=n*(n-1)*(n-2)/6;
    while(true){
        if(l>=n) break;
        if((v[r+1]-v[l])*2<L){//this ok,next not ok
            r++;
            continue;
        }
        // cout<<r<<": "<<((v[r+1]-v[l])+L)%L<<endl;
        ans-=(r-l)*(r-l-1)/2;
        // cout<<l<<' '<<r<<endl;
        l++;
    }
    cout<<ans;
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