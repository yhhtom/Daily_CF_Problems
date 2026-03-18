//AC
#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int x,y;
    cin>>x>>y;
    int ans=0;
    if(x>y){
        while(x!=y){
            int old=x;
            ans++;
            x=max((2*x)/3+1,y);
            if(x==old){
                cout<<"-1\n";
                return;
            }
        }
    }else{
        while(x!=y){
            int old=x;
            ans++;
            x=min(2*x,y);
            if(x==old){
                cout<<"-1\n";
                return;
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