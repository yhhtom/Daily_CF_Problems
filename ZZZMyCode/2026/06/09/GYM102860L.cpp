#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
#define i64 long long
using namespace std;
struct BIT {
    vector<i64> a, b;
    int n;

    BIT(int n) : n(n), a(n + 1), b(n + 1) {}
    void rangeAdd(int l, int r, i64 val) { // 区间修改
        auto add = [&](int pos, i64 val) {
            for (int i = pos; i <= n; i += i & -i) {
                a[i] += val;
                b[i] += pos * val;
            }
        };
        add(l, val), add(r + 1, -val);
    }
    i64 rangeSum(int l, int r) { // 区间和查询
        auto sum = [&](int x) {
            i64 ans = 0;
            for (int i = x; i; i -= i & -i) {
                ans += (x + 1) * a[i] - b[i];
            }
            return ans;
        };
        return sum(r) - sum(l - 1);
    }
};
void solve(){
    int n,q;
    cin>>n>>q;
    BIT fenxk(n),fenxb(n),fenyk(n),fenyb(n);
    fenxk.rangeAdd(1,n,1);
    auto get = [&] (int x) -> PII {
        return {fenxk.rangeSum(x,x)*x+fenxb.rangeSum(x,x),fenyk.rangeSum(x,x)*x+fenyb.rangeSum(x,x)};
    };
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            // cout<<get(l).first<<' '<<get(r).first<<'\n';
            if(get(l).second==get(r).second){
                fenxk.rangeAdd(l,r,-1);
                fenxb.rangeAdd(l,r,l);
                fenyk.rangeAdd(l,r,1);
                fenyb.rangeAdd(l,r,-l);
                // cout<<1;
            }else{
                fenyk.rangeAdd(l,r,-1);
                fenyb.rangeAdd(l,r,l);
                fenxk.rangeAdd(l,r,1);
                fenxb.rangeAdd(l,r,-l);
                // cout<<2;
            }
        }else{
            int x;
            cin>>x;
            cout<<get(x).first<<' '<<get(x).second<<'\n';
        }
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