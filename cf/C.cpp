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
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i][0];
    for(int i=0;i<n;i++) cin>>v[i][1];
    int ans=0;
    for(int i=0;i<n;){
        if(v[i][0]==v[i][1]){
            // cout<<1<<endl;
            i++;
        }else if(i<n-1&&v[i][0]==v[i+1][0]&&v[i][1]==v[i+1][1]){
            // cout<<2<<endl;
            i+=2;
        }else if(i<n-1&&(v[i][0]!=v[i+1][0]||v[i][1]!=v[i+1][1])){
            // cout<<3<<endl;
            i++;
            ans++;
        }else{
            // cout<<4<<endl;
            ans++;
            i++;
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