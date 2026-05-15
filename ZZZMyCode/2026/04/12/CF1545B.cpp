#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
int mod=998244353;
int fac[100005];
int fpow(int a,int b){
    int r=1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1) r=r*a%mod;
    }
    return r;
}
int inv(int a){
    return fpow(a,mod-2);
}
int com(int a,int b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+="0";
    int a=0,m=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'&&s[i+1]=='1'){
            m++;
            s[i]='0';
            s[i+1]='0';
        }else if(s[i]=='1'&&s[i+1]=='0'){
            a++;
        }
    }
    cout<<com(n-a-m,m)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fac[0]=1;
    for(int i=1;i<100005;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}