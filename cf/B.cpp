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
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        int maxv=max(v[i],v[i+1]);
        int minv=min(v[i],v[i+1]);
        int gcdv=gcd(v[i],v[i+1]);
        if(maxv-minv==gcdv){
            ans++;
            for(int j=i+2;j<n;j--){
                maxv=max(v[j],maxv);
                minv=min(v[j],minv);
                gcdv=gcd(v[j],gcdv);;
                if(maxv-minv==gcdv){
                    ans++;
                }else{
                    break;
                }
            }
        }
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