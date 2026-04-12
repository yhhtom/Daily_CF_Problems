#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;
const vector<int> p={1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5),b(n+5),c(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        if(i==1) c[i]=gcd(a[1],a[2]);
        else if(i==n) c[i]=gcd(a[n],a[n-1]);
        else c[i]=lcm(gcd(a[i],a[i-1]),gcd(a[i],a[i+1]));

        if(c[i]>b[i]) c[i]=a[i];
    }
    int m=p.size();
    vector<vector<int>> dp(n+5,vector<int>(m,LLONG_MIN));
    for(int i=0;i<m;i++){
        if(i==0){
            if(a[1]==c[1]){
                dp[1][0]=0;
            }else{
                dp[1][0]=1;
            }
            continue;
        }
        int temp=c[1]*p[i];
        if(temp<=b[1]&&temp!=a[1]&&gcd(temp,c[2])==gcd(a[1],a[2])){
            dp[1][i]=1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==0){
                    if(c[i]==a[i]) dp[i][j]=max(dp[i][j],dp[i-1][k]);
                    else dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                    continue;
                }
                int temp1=c[i-1]*p[k];
                int temp2=c[i]*p[j];
                if(temp2<=b[i]&&temp2!=a[i]&&gcd(temp1,temp2)==gcd(a[i-1],a[i])){
                    if(i<n){
                        if(gcd(temp2,c[i+1])==gcd(a[i],a[i+1])) dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                    }else{
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans=max(ans,dp[n][i]);
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