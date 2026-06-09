#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
const int MOD=1e9+7;
const int M=30;
const int N=1e5+5;
int fp(int a,int b){
    int r=1;
    for(;b;b>>=1,a=a*a%MOD){if(b&1) r=r*a%MOD;}
    return r;
}
int inv(int a){
    return fp(a,MOD-2);
}
int opp(int a){
    return (1-a+MOD)%MOD;
}
int cnt[M][M][4];
int p[N];//P of choosing odd in i elements
int dp[4];
int ndp[4];
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                cnt[i][j][k]=0;
            }
        }
    }
    for(int k=0;k<n;k++){
        int temp;
        cin>>temp;
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                cnt[i][j][((temp>>i)&1)*2+((temp>>j)&1)]++;
            }
        }
    }
    //prob
    p[0]=0;
    int p1=x*inv(y)%MOD;
    int p0=opp(p1);
    for(int i=1;i<=n;i++){
        p[i]=(p[i-1]*p0%MOD+opp(p[i-1])*p1%MOD)%MOD;
    }
    int ans=0;
    //dp[k] denotes the P when Bi Bj is at state k
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++) dp[k]=0;
            dp[0]=1;
            for(int si=0;si<4;si++){
                int psi=p[cnt[i][j][si]];
                for(int sj=0;sj<4;sj++){
                    ndp[sj]=(dp[sj^si]*psi%MOD+dp[sj]*opp(psi)%MOD)%MOD;
                }
                for(int k=0;k<4;k++) dp[k]=ndp[k];
            }
            ans+=(1ll<<i+j)%MOD*dp[3]%MOD;
            ans%=MOD;
        }
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