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
	cin >> n;
    int x=1;
    cout<<x<<' ';
    int step1=2*n+1,step2=1;;
    for(int i=1;i<n+2;i++){
        if(i&1) x+=step1,step1-=2;
        else x-=step2,step2+=2;
        cout<<x<<' ';
    }
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