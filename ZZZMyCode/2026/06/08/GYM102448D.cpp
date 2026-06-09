#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
const int M = 1e5+5;
pair<double,int> v[M];
bool check(double r, int n){
    for(int i=0;i<n;i++){
        if(r>=v[i].first){
            // cout<<r<<" vs: "<<sqrt(v[i].first)<<endl;
            r+=v[i].second;
            
        }else{
            return false;
        }
    }
    return true;
}
void solve(){
    int n;
    double x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
        double tempx,tempy,tempr;
        cin>>tempx>>tempy>>tempr;
        double d = sqrt((tempx - x)*(tempx - x)+(tempy - y)*(tempy - y));
        v[i].first=d - tempr;
        v[i].second=tempr;
    }
    sort(v,v+n);
    double l=0,r=1;
    while(!check(r,n)){
        r*=2;
    }
    double ans=r;
    for(int i=0;i<128;i++){
        double mid = l+(r-l)/2;
        if(check(mid,n)){
            ans=mid;
            r=mid;
        }else{
            l=mid;
        }
        // cout<<r<<endl;
    }
    cout<<ans<<'\n';
    // for(int i=0;i<n;i++){
    //     cout<<v[i].first<<' '<<v[i].second<<endl;
    // }
    // cout<<check(424.287,n)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t=1;
    cout<<fixed<<setprecision(7);
    while(t--){
        solve();
    }
    return 0;
}