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
    vector<vector<int>> trie(1,vector<int>(2,0));
    int ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        int temp=v[i];
        int j=0;
        int res=0;
        while(temp){
            int b=temp%2;
            temp>>=1;
            if(b==1){
                if(trie[j][1]==1)
            }else{

            }
        }
    }
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