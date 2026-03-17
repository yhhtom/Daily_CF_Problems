#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n,m,r1,c1,r2,c2;
    cin>>n>>m>>r1>>c1>>r2>>c2;
    if((n*m)&1==1){
        cout<<"NO";
    }else if(n==1||m==1){
        if(m==1){
            swap(n,m);
            swap(r1,c1);
            swap(r2,c2);
        }
        if(c1>c2){
            swap(c1,c2);
        }
        cout<<(((c1%2==1)&&((c2-c1)%2==1)&&((m-c2)%2==1))?"YES":"NO");
    }else{
        cout<<(((r1+c1+r2+c2)&1)?"YES":"NO");
    }
    cout<<'\n';
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